#include <iostream>

long count_walls(bool const* const* maze, size_t num_rows, size_t num_cols){
    //      not change maze / not change maze_ptrs values.
    long c = 0;
    for(size_t row = 0; row < num_rows; row++)
        for(size_t col = 0; col < num_cols; col++)
            c += maze[row][col];
    return c;
}

enum class direction {up, right, down, left};

struct position{
    size_t x, y;
};

// To make good recursion case, need to close base case.
position* solve(bool const* const* maze, size_t num_rows, size_t num_cols,
                size_t x, size_t y, size_t target_x, size_t target_y, direction last_dir, size_t& path_length){
    if(x == target_x && y == target_y){
        path_length = 0;
        return new position[0];
    };
    size_t l = path_length;
    if(y > 0 && !maze[y - 1][x] && last_dir != direction::down){ // UP
        position* p = solve(maze, num_rows, num_cols, x, y - 1, target_x, target_y, direction::up, l);
        //if(p){ Notate explicit p != nullptr. 
        #define CHECK(p)    if(p != nullptr){   \
            position* new_p = new position[l + 1];  \
            new_p[0].x = x; \
            new_p[0].y = y; \
            for(size_t i = 0; i < l; i++)   \
                new_p[i + 1] = p[i];    \
            delete [] p;    \
            path_length = l + 1;    \
            return new_p;   \
        }
        CHECK(p);
    }
    if(x < num_cols - 1 && !maze[y][x + 1] && last_dir != direction::left){ // Goes to right;
        position* p = solve(maze, num_rows, num_cols, x + 1, y, target_x, target_y, direction::right, l);
        CHECK(p);
    }
    if( y < num_rows - 1 && !maze[y + 1][x] && last_dir != direction::up){ // Down
        position* p = solve(maze, num_rows, num_cols, x, y + 1, target_x, target_y, direction::down, l);
        CHECK(p);
    }
    if(x > 0 && !maze[y][x - 1] && last_dir != direction::right){ // Left
        position* p = solve(maze, num_rows, num_cols, x - 1, y, target_x, target_y, direction::left, l);
        CHECK(p);
    }
    return nullptr;
}

using namespace std;

int main(){
    bool const maze[][11] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Represent 1(true) as wall.
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, // Address as linearly. ex) maze[3][2] == maze + 35.
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    };

    bool const *maze_ptrs[sizeof(maze) / sizeof(maze[0])]; // array of pointer to const boolean. Reading type name as inside out.(Right to left.)
    for(size_t i = 0; i < sizeof(maze) / sizeof(maze[0]); i++)
        maze_ptrs[i] = maze[i];
    size_t pos_len;
    position* poss = solve(maze_ptrs, sizeof(maze) / sizeof(maze[0]), sizeof(maze[0]) / sizeof(maze[0][0]), 0, 2, 9, 5, direction::right, pos_len);
                                    // shows how many rows                    columns in first row.
    for(size_t i = 0; i < pos_len; i++){
        cout << poss[i].x << ", " << poss[i].y << '\n';
    }
    delete [] poss;
    return 0;
}