
/* Generated data (by glib-mkenums) */


#include "config.h"

#include "zpj-enums.h"
#include "zpj-skydrive-entry.h"


/* enumerations from "zpj-skydrive-entry.h" */


GType
zpj_skydrive_entry_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {


            { ZPJ_SKYDRIVE_ENTRY_TYPE_FILE, "ZPJ_SKYDRIVE_ENTRY_TYPE_FILE", "file" },


            { ZPJ_SKYDRIVE_ENTRY_TYPE_FOLDER, "ZPJ_SKYDRIVE_ENTRY_TYPE_FOLDER", "folder" },


            { ZPJ_SKYDRIVE_ENTRY_TYPE_PHOTO, "ZPJ_SKYDRIVE_ENTRY_TYPE_PHOTO", "photo" },


            { ZPJ_SKYDRIVE_ENTRY_TYPE_INVALID, "ZPJ_SKYDRIVE_ENTRY_TYPE_INVALID", "invalid" },


            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("ZpjSkydriveEntryType"), values);
    }
    return etype;
}



/* Generated data ends here */

