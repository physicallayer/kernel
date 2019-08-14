#pragma once

#include <linux/string.h>
#include <linux/slab.h>

#include "rule.h"
#include "fileio.h"
#include "plstring.h"

void readRule(Rule* inbound, Rule* outbound);
