/* raw.h */

#ifndef RAW_H
#define RAW_H

#include "core/object/reference.h"
#include "core/variant/variant.h"
#include "core/error/error_list.h"
#include "core/error/error_macros.h"

class Raw : public Reference {
    GDCLASS(Raw, Reference);

private:

	union DataUnion {
		uint8_t u8;
		uint16_t u16;
		uint32_t u32;

		int8_t i8;
		int16_t i16;
		int32_t i32;

		float_t f32;
		double_t f64;

		uint8_t byte[8];
	};

	PackedByteArray data;

protected:
    static void _bind_methods();

public:

	uint8_t get_u8(size_t offset);
	uint16_t get_u16(size_t offset);
	uint32_t get_u32(size_t offset);

	int8_t get_i8(size_t offset);
	int16_t get_i16(size_t offset);
	int32_t get_i32(size_t offset);

	float get_f32(size_t offset);
	float get_f64(size_t offset);

	Vector3 get_vec(size_t offset);
	String get_string(size_t offset, size_t max);

	void set_data( PackedByteArray _data);
	PackedByteArray get_data() const;

	Raw();
};

#endif
