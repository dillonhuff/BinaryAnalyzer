#ifndef CLASS_32_DECODER_H_
#define CLASS_32_DECODER_H_

#include "arm/class_32_bit_selector.h"
#include "arm/noop_decoder.h"
#include "arm/noop_processor.h"
#include "arm/table_decoder.h"

bit_p undef_32_1[14] = {any, one,
			any, any, any, any, any, any, any, any, any, any, any,
			any};
bit_p undef_32_2[14] = {one, zero,
			any, any, any, any, any, any, any, any, any, any, any,
			zero};
bit_p branch_and_misc_control[14] = {one, zero,
				     any, any, any, any, any, any, any, any, any, any, any,
				     one};

bit_p* instr_class_32[3] = {undef_32_1, undef_32_2, branch_and_misc_control};

decoder* class_32_sub_decoders[3] =
  {new noop_decoder(), new noop_decoder(), new noop_decoder()};

auto class_32_decode_table =
  bit_pattern_table<decoder*>(instr_class_32, &*class_32_sub_decoders, 3, 14);

auto noop_proc = new noop_processor();
auto bit_selector = new class_32_bit_selector();

auto class_32_decoder =
  table_decoder(noop_proc, bit_selector, &class_32_decode_table);

#endif
