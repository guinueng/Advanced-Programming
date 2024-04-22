#include "rpg.h"

int travel_speed(character const* c, terrain_type t){
    switch(t){
        case terrain_type::water:
            return c -> flying_speed;
        case terrain_type::volcano:
            return c -> walking_speed;
        case terrain_type::sand:
            int sand_walk_speed = (c -> walking_speed + 1) / 2;
            if(sand_walk_speed > c -> flying_speed)
                return sand_walk_speed;
            else
                return c -> flying_speed;
    }
    __builtin_unreachable();
}

int travel_speed(character const* cs, size_t n, terrain_type t){
    int min_speed = 0;
    for(size_t i = 0; i < n; i++){
        int tmp_speed = travel_speed(cs + i, t);
        if( min_speed > tmp_speed )
            min_speed = tmp_speed;
        else if( i == 0 )
            min_speed = tmp_speed;
    }
    return min_speed;
}

int travel_speed(character const* cs, size_t cs_n, terrain_type const* ts, size_t ts_n){
    int tot_speed = 0;
    for(size_t i = 0; i < ts_n; i++){
        tot_speed += travel_speed(cs, cs_n, *(ts + i));
    }
    return tot_speed;
}

void remove_slowest(character const* cs, character* out, size_t cs_n, terrain_type const* ts, size_t ts_n){
    int min_speed = 0;
    size_t min_pos = 0;
    for(size_t i = 0; i < cs_n; i++){
        int tmp = travel_speed(&cs[i], 1, ts, ts_n);

        if(i == 0)
            min_speed = tmp;
        else{
            if(min_speed > tmp){
                min_speed = tmp;
                min_pos = i;
            }
        }
    }

    for(size_t i = 0; i < cs_n - 1; i++){
        if(i < min_pos)
            out[i] = cs[i];
        else
            out[i] = cs[i + 1];
    }
}