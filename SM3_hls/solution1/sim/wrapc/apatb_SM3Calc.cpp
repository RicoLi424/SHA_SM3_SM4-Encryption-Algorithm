// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// apint = uint32
#define uint32 int
// apint = uint8
#define uint8 char

// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "message"
#define AUTOTB_TVIN_message  "../tv/cdatafile/c.SM3Calc.autotvin_message.dat"
// wrapc file define: "messageLen"
#define AUTOTB_TVIN_messageLen  "../tv/cdatafile/c.SM3Calc.autotvin_messageLen.dat"
// wrapc file define: "digest"
#define AUTOTB_TVOUT_digest  "../tv/cdatafile/c.SM3Calc.autotvout_digest.dat"
#define AUTOTB_TVIN_digest  "../tv/cdatafile/c.SM3Calc.autotvin_digest.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "digest"
#define AUTOTB_TVOUT_PC_digest  "../tv/rtldatafile/rtl.SM3Calc.autotvout_digest.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			message_depth = 0;
			messageLen_depth = 0;
			digest_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{message " << message_depth << "}\n";
			total_list << "{messageLen " << messageLen_depth << "}\n";
			total_list << "{digest " << digest_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int message_depth;
		int messageLen_depth;
		int digest_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern "C" void SM3Calc (
uint8 message[32],
uint8 messageLen,
uint32 digest[8]);

extern "C" void AESL_WRAP_SM3Calc (
uint8 message[32],
uint8 messageLen,
uint32 digest[8])
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "digest"
		aesl_fh.read(AUTOTB_TVOUT_PC_digest, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_digest, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_digest, AESL_token); // data

			sc_bv<32> *digest_pc_buffer = new sc_bv<32>[8];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'digest', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'digest', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					digest_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_digest, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_digest))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: digest
				{
					// bitslice(31, 0)
					// {
						// celement: digest(31, 0)
						// {
							sc_lv<32>* digest_lv0_0_7_1 = new sc_lv<32>[8];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: digest(31, 0)
						{
							// carray: (0) => (7) @ (1)
							for (int i_0 = 0; i_0 <= 7; i_0 += 1)
							{
								if (&(digest[0]) != NULL) // check the null address if the c port is array or others
								{
									digest_lv0_0_7_1[hls_map_index].range(31, 0) = sc_bv<32>(digest_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: digest(31, 0)
						{
							// carray: (0) => (7) @ (1)
							for (int i_0 = 0; i_0 <= 7; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : digest[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : digest[0]
								// output_left_conversion : digest[i_0]
								// output_type_conversion : (digest_lv0_0_7_1[hls_map_index]).to_uint64()
								if (&(digest[0]) != NULL) // check the null address if the c port is array or others
								{
									digest[i_0] = (digest_lv0_0_7_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] digest_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "message"
		char* tvin_message = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_message);

		// "messageLen"
		char* tvin_messageLen = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_messageLen);

		// "digest"
		char* tvin_digest = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_digest);
		char* tvout_digest = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_digest);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_message, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_message, tvin_message);

		sc_bv<8>* message_tvin_wrapc_buffer = new sc_bv<8>[32];

		// RTL Name: message
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: message(7, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : message[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : message[0]
						// regulate_c_name       : message
						// input_type_conversion : message[i_0]
						if (&(message[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> message_tmp_mem;
							message_tmp_mem = message[i_0];
							message_tvin_wrapc_buffer[hls_map_index].range(7, 0) = message_tmp_mem.range(7, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 32; i++)
		{
			sprintf(tvin_message, "%s\n", (message_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_message, tvin_message);
		}

		tcl_file.set_num(32, &tcl_file.message_depth);
		sprintf(tvin_message, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_message, tvin_message);

		// release memory allocation
		delete [] message_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_messageLen, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_messageLen, tvin_messageLen);

		sc_bv<8> messageLen_tvin_wrapc_buffer;

		// RTL Name: messageLen
		{
			// bitslice(7, 0)
			{
				// celement: messageLen(7, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : messageLen
						// sub_1st_elem          : 
						// ori_name_1st_elem     : messageLen
						// regulate_c_name       : messageLen
						// input_type_conversion : messageLen
						if (&(messageLen) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> messageLen_tmp_mem;
							messageLen_tmp_mem = messageLen;
							messageLen_tvin_wrapc_buffer.range(7, 0) = messageLen_tmp_mem.range(7, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_messageLen, "%s\n", (messageLen_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_messageLen, tvin_messageLen);
		}

		tcl_file.set_num(1, &tcl_file.messageLen_depth);
		sprintf(tvin_messageLen, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_messageLen, tvin_messageLen);

		// [[transaction]]
		sprintf(tvin_digest, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_digest, tvin_digest);

		sc_bv<32>* digest_tvin_wrapc_buffer = new sc_bv<32>[8];

		// RTL Name: digest
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: digest(31, 0)
				{
					// carray: (0) => (7) @ (1)
					for (int i_0 = 0; i_0 <= 7; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : digest[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : digest[0]
						// regulate_c_name       : digest
						// input_type_conversion : digest[i_0]
						if (&(digest[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> digest_tmp_mem;
							digest_tmp_mem = digest[i_0];
							digest_tvin_wrapc_buffer[hls_map_index].range(31, 0) = digest_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 8; i++)
		{
			sprintf(tvin_digest, "%s\n", (digest_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_digest, tvin_digest);
		}

		tcl_file.set_num(8, &tcl_file.digest_depth);
		sprintf(tvin_digest, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_digest, tvin_digest);

		// release memory allocation
		delete [] digest_tvin_wrapc_buffer;

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		SM3Calc(message, messageLen, digest);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_digest, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_digest, tvout_digest);

		sc_bv<32>* digest_tvout_wrapc_buffer = new sc_bv<32>[8];

		// RTL Name: digest
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: digest(31, 0)
				{
					// carray: (0) => (7) @ (1)
					for (int i_0 = 0; i_0 <= 7; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : digest[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : digest[0]
						// regulate_c_name       : digest
						// input_type_conversion : digest[i_0]
						if (&(digest[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> digest_tmp_mem;
							digest_tmp_mem = digest[i_0];
							digest_tvout_wrapc_buffer[hls_map_index].range(31, 0) = digest_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 8; i++)
		{
			sprintf(tvout_digest, "%s\n", (digest_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_digest, tvout_digest);
		}

		tcl_file.set_num(8, &tcl_file.digest_depth);
		sprintf(tvout_digest, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_digest, tvout_digest);

		// release memory allocation
		delete [] digest_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "message"
		delete [] tvin_message;
		// release memory allocation: "messageLen"
		delete [] tvin_messageLen;
		// release memory allocation: "digest"
		delete [] tvout_digest;
		delete [] tvin_digest;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}


// apint = uint32
#undef uint32

// apint = uint8
#undef uint8
