#ifndef RPG_H
#define RPG_H

#include <cstddef>

enum class terrain_type{ water, sand, volcano };

struct character{
    int walking_speed;
    int flying_speed;
};

int travel_speed(character const* c, terrain_type t);

int travel_speed(character const* cs, size_t n, terrain_type t);

int travel_speed(character const* cs, size_t cs_n, terrain_type const* ts, size_t ts_n);

void remove_slowest(character const*, character*, size_t, terrain_type const*, size_t);

#endif
