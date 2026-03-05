#pragma once

enum class ATMStateType
{
    IDLE,
    HAS_CARD,
    AUTHENTICATED,
    TRANSACTION
};