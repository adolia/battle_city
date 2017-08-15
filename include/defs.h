#ifndef DEFS_H
#define DEFS_H

#define FRAMES 30
#define PLAYER_TANK_SPEED 6
#define AI_TANK_SPEED 3
#define SHELL_SPEED (PLAYER_TANK_SPEED * 2)
#define WIDTH 50
#define HEIGHT 50

#define ENEMIES_COUNT 16
#define MAX_ALIVE_ENEMIES 3
#define PLAYER_RESPAWN_IVAL
#define ENEMY_RESPAWN_IVAL 3000
#define AI_TICK_IVAL 1000


/* Since the std::size expressions from C++17 */

#include <ctime>

namespace std
{
    template <class T, std::size_t N>
    constexpr std::size_t size (const T (&array)[N]) noexcept
    {
        return array != nullptr ? N : 0;
    }

    template <class C>
    constexpr auto size(const C& c) -> decltype(c.size())
    {
        return c.size();
    }
}
#endif // DEFS_H
