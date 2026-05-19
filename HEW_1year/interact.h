#pragma once
#ifndef _INTERACT_H_
#define _INTERACT_H_
#include "player.h"
#include "paint.h"
#include "field.h"
#include "customer.h"
#include "mix.h"

bool PlayerInteractPaint(PLAYER* ptPlayer);
bool PlayerInteractField(PLAYER* ptPlayer);
bool CustInteractGet(CUST* ptCust);
bool PlayerInteractMixSet(PLAYER* ptPlayer);
bool PlayerInteractMixGet(PLAYER* ptPlayer);
#endif