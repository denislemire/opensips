/*
 * Copyright (C) 2018 OpenSIPS Project
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef _TM_CLUSTER_H_
#define _TM_CLUSTER_H_

#include "../../str.h"
#include "../clusterer/api.h"

#define TM_CLUSTER_DEFAULT_PARAM "cid"

extern int tm_replicate_cluster;
extern int tm_accept_cluster;
extern str tm_cluster_param;
extern str tm_cid;
extern struct clusterer_binds cluster_api;

/* initializes cluster support for tm */
int tm_init_cluster(void);

/* returns true if clusterer is enabled */
#define tm_cluster_enabled() (cluster_api.register_module != 0)

/* returns the via parameter for the cluster */
#define tm_via_cid() (tm_cluster_enabled()?&tm_cid:0)


#endif /* _TM_CLUSTER_H_ */