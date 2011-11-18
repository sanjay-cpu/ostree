/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2011 Colin Walters <walters@verbum.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Colin Walters <walters@verbum.org>
 */

#ifndef __OSTREE_BUILTINS__
#define __OSTREE_BUILTINS__

#include <glib-object.h>

G_BEGIN_DECLS

typedef enum {
  OSTREE_BUILTIN_FLAG_NONE = 0,
  OSTREE_BUILTIN_FLAG_NO_REPO = 1,
} OstreeBuiltinFlags;

typedef struct {
  const char *name;
  gboolean (*fn) (int argc, char **argv, const char *repo, GError **error);
  int flags; /* OstreeBuiltinFlags */
} OstreeBuiltin;

gboolean ostree_builtin_checkout (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_checksum (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_commit (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_compose (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_diff (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_init (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_local_clone (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_log (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_pull (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_run_triggers (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_fsck (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_show (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_rev_parse (int argc, char **argv, const char *repo, GError **error);
gboolean ostree_builtin_remote (int argc, char **argv, const char *repo, GError **error);

G_END_DECLS

#endif
