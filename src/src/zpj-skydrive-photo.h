/*
 * Zapojit - GLib/GObject wrapper for the SkyDrive and Hotmail REST APIs
 * Copyright © 2012 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef ZPJ_SKYDRIVE_PHOTO_H
#define ZPJ_SKYDRIVE_PHOTO_H

#include <json-glib/json-glib.h>

#include "zpj-skydrive-file.h"

G_BEGIN_DECLS

#define ZPJ_TYPE_SKYDRIVE_PHOTO (zpj_skydrive_photo_get_type ())

#define ZPJ_SKYDRIVE_PHOTO(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
   ZPJ_TYPE_SKYDRIVE_PHOTO, ZpjSkydrivePhoto))

#define ZPJ_SKYDRIVE_PHOTO_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
   ZPJ_TYPE_SKYDRIVE_PHOTO, ZpjSkydrivePhotoClass))

#define ZPJ_IS_SKYDRIVE_PHOTO(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
   ZPJ_TYPE_SKYDRIVE_PHOTO))

#define ZPJ_IS_SKYDRIVE_PHOTO_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
   ZPJ_TYPE_SKYDRIVE_PHOTO))

#define ZPJ_SKYDRIVE_PHOTO_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
   ZPJ_TYPE_SKYDRIVE_PHOTO, ZpjSkydrivePhotoClass))

typedef struct _ZpjSkydrivePhoto      ZpjSkydrivePhoto;
typedef struct _ZpjSkydrivePhotoClass ZpjSkydrivePhotoClass;

/**
 * ZpjSkydrivePhoto:
 *
 * The #ZpjSkydrivePhoto structure contains only private data and
 * should only be accessed using the provided API.
 */
struct _ZpjSkydrivePhoto
{
  ZpjSkydriveFile parent_instance;
};

/**
 * ZpjSkydrivePhotoClass:
 * @parent_class: The parent class.
 *
 * Class structure for #ZpjSkydrivePhoto.
 */
struct _ZpjSkydrivePhotoClass
{
  ZpjSkydriveFileClass parent_class;
};

GType               zpj_skydrive_photo_get_type           (void) G_GNUC_CONST;

ZpjSkydriveEntry   *zpj_skydrive_photo_new                (JsonNode *node);

G_END_DECLS

#endif /* ZPJ_SKYDRIVE_PHOTO_H */
