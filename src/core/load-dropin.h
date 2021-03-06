/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

/***
  This file is part of systemd.

  Copyright 2010 Lennart Poettering
***/

#include "dropin.h"
#include "unit.h"

/* Read service data supplementary drop-in directories */

static inline int unit_find_dropin_paths(Unit *u, char ***paths) {
        assert(u);

        return unit_file_find_dropin_conf_paths(NULL,
                                                u->manager->lookup_paths.search_path,
                                                u->manager->unit_path_cache,
                                                u->names,
                                                paths);
}

int unit_load_dropin(Unit *u);
