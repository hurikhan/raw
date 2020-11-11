
#include "raw.h"

uint8_t Raw::get_u8(size_t offset) {
	return data[offset];
}

uint16_t Raw::get_u16(size_t offset) {
	DataUnion du;

	du.byte[0] = data[offset];
	du.byte[1] = data[offset + 1];

	return du.u16;
}

uint32_t Raw::get_u32(size_t offset) {
	DataUnion du;

	du.byte[0] = data[offset];
	du.byte[1] = data[offset + 1];
	du.byte[2] = data[offset + 2];
	du.byte[3] = data[offset + 3];

	return du.u32;
}

int8_t Raw::get_i8(size_t offset) {
	DataUnion du;

	du.byte[0] = data[offset];

	return du.i8;
}

int16_t Raw::get_i16(size_t offset) {
	DataUnion du;

	du.byte[0] = data[offset];
	du.byte[1] = data[offset + 1];

	return du.u16;
}

int32_t Raw::get_i32(size_t offset) {
	DataUnion du;

	du.byte[0] = data[offset];
	du.byte[1] = data[offset + 1];
	du.byte[2] = data[offset + 2];
	du.byte[3] = data[offset + 3];

	return du.u32;
}

float Raw::get_f32(size_t offset) {
	DataUnion du;

	du.byte[0] = data[offset];
	du.byte[1] = data[offset + 1];
	du.byte[2] = data[offset + 2];
	du.byte[3] = data[offset + 3];

	return float(du.f32);
}

float Raw::get_f64(size_t offset) {
	DataUnion du;

	du.byte[0] = data[offset];
	du.byte[1] = data[offset + 1];
	du.byte[2] = data[offset + 2];
	du.byte[3] = data[offset + 3];
	du.byte[4] = data[offset + 4];
	du.byte[5] = data[offset + 5];
	du.byte[6] = data[offset + 6];
	du.byte[7] = data[offset + 7];

	return float(du.f64);
}

Vector3 Raw::get_vec(size_t offset) {

	float_t x, y, z;

	x = get_f32(offset + 0);
	y = get_f32(offset + 4);
	z = get_f32(offset + 8);

	Vector3 v;

	v.x = x;
	v.y = y;
	v.z = z;

	return v;
}

String Raw::get_string(size_t offset, size_t max) {

	char *cstr = (char*) memalloc(max+1);	

	for(size_t i=0; i < max; i++) {
		cstr[i] = data[offset+i];
		if (data[offset+i] == 0)
			break;
	}

	if (cstr[max-2] != 0)
		cstr[max-1] = 0;

	String s = String(cstr);	

	memfree(cstr);

	return s;
}

void Raw::set_data( PackedByteArray _data ) {
	data = _data;
}

PackedByteArray Raw::get_data() const {

	return data;
}


void Raw::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_u8", "offset"), &Raw::get_u8);
	ClassDB::bind_method(D_METHOD("get_u16", "offset"), &Raw::get_u16);
	ClassDB::bind_method(D_METHOD("get_u32", "offset"), &Raw::get_u32);

	ClassDB::bind_method(D_METHOD("get_i8", "offset"), &Raw::get_i8);
	ClassDB::bind_method(D_METHOD("get_i16", "offset"), &Raw::get_i16);
	ClassDB::bind_method(D_METHOD("get_i32", "offset"), &Raw::get_i32);

	ClassDB::bind_method(D_METHOD("get_f32", "offset"), &Raw::get_f32);
	ClassDB::bind_method(D_METHOD("get_f64", "offset"), &Raw::get_f64);

	ClassDB::bind_method(D_METHOD("get_vec", "offset"), &Raw::get_vec);
	ClassDB::bind_method(D_METHOD("get_string", "offset", "max"), &Raw::get_string);

	ClassDB::bind_method(D_METHOD("set_data", "data"), &Raw::set_data);
	ClassDB::bind_method(D_METHOD("get_data"), &Raw::set_data);
}


Raw::Raw() {
}
