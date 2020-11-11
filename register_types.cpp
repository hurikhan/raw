/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "raw.h"

void register_raw_types() {
    ClassDB::register_class<Raw>();
}

void unregister_raw_types() {
   // Nothing to do here in this example.
}
