#ifndef ACLIB_SHARED_MEMORY_ACLIB_HPP
#define ACLIB_SHARED_MEMORY_ACLIB_HPP

#include <cstdint>
#include <xlocinfo.h>

namespace ACLIB
{
    typedef std::uint32_t Uint32;
    typedef std::uint64_t Uint64;
    typedef std::int32_t  Sint32;
    typedef std::int64_t  Sint64;
    typedef wchar_t       WChar;

    typedef Uint32 EventType;

    enum EVENT : EventType
    {
        BASIC   = 0x00000000,

        PHYSICS = 0x10000000,

        GEAR_CHANGED,
        DAMAGE_CHANGED,
        TYRES_OUT_CHANGED,
        DRS_CHANGED,
        DRS_AVAILABLE_CHANGED,
        DRS_ENABLE_CHANGED,

        GRAPHICS = 0x20000000,

        STATUS_CHANGED,
        STATUS_OFF,
        STATUS_REPLAY,
        STATUS_LIVE,
        STATUS_PAUSE,

        SESSION_CHANGED,
        SESSION_UNKNOWN,
        SESSION_PRACTICE,
        SESSION_QUALIFYING,
        SESSION_RACE,
        SESSION_HOTLAP,
        SESSION_TIME_ATTACK,
        SESSION_DRIFT,
        SESSION_DRAG,

        COMPLETED_LAPS_CHANGED,
        POSITION_CHANGED,
        IS_IN_PIT,
        TYRE_CHANGED,
        PENALTY_CHANGED,

        FLAG_CHANGED,
        FLAG_NONE,
        FLAG_BLUE,
        FLAG_YELLOW,
        FLAG_BLACK,
        FLAG_WHITE,
        FLAG_CHECKERED,
        FLAG_PENALTY,

        STATICS = 0x40000000,
    };

}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_ACLIB_HPP
