module sm4_Sbox (data_in,data_out);
input    [7:0]    data_in;
output   [7:0]    data_out;
reg      [7:0]    data_out;
  
always @(data_in)
  case(data_in)
  	8'h00  :  data_out=8'hd6;   8'h01  :  data_out=8'h90;   8'h02  :  data_out=8'he9;   8'h03  :  data_out=8'hfe;   
	8'h04  :  data_out=8'hcc;   8'h05  :  data_out=8'he1;   8'h06  :  data_out=8'h3d;   8'h07  :  data_out=8'hb7;   
	8'h08  :  data_out=8'h16;   8'h09  :  data_out=8'hb6;   8'h0a  :  data_out=8'h14;   8'h0b  :  data_out=8'hc2;
	8'h0c  :  data_out=8'h28;   8'h0d  :  data_out=8'hfb;   8'h0e  :  data_out=8'h2c;   8'h0f  :  data_out=8'h05;
	
	8'h10  :  data_out=8'h2b;   8'h11  :  data_out=8'h67;   8'h12  :  data_out=8'h9a;   8'h13  :  data_out=8'h76;   
	8'h14  :  data_out=8'h2a;   8'h15  :  data_out=8'hbe;   8'h16  :  data_out=8'h04;   8'h17  :  data_out=8'hc3;   
	8'h18  :  data_out=8'haa;   8'h19  :  data_out=8'h44;   8'h1a  :  data_out=8'h13;   8'h1b  :  data_out=8'h26;
	8'h1c  :  data_out=8'h49;   8'h1d  :  data_out=8'h86;   8'h1e  :  data_out=8'h06;   8'h1f  :  data_out=8'h99;
	
	8'h20  :  data_out=8'h9c;   8'h21  :  data_out=8'h42;   8'h22  :  data_out=8'h50;   8'h23  :  data_out=8'hf4;   
	8'h24  :  data_out=8'h91;   8'h25  :  data_out=8'hef;   8'h26  :  data_out=8'h98;   8'h27  :  data_out=8'h7a;   
	8'h28  :  data_out=8'h33;   8'h29  :  data_out=8'h54;   8'h2a  :  data_out=8'h0b;   8'h2b  :  data_out=8'h43;
	8'h2c  :  data_out=8'hed;   8'h2d  :  data_out=8'hcf;   8'h2e  :  data_out=8'hac;   8'h2f  :  data_out=8'h62;
	
	8'h30  :  data_out=8'he4;   8'h31  :  data_out=8'hb3;   8'h32  :  data_out=8'h1c;   8'h33  :  data_out=8'ha9;   
	8'h34  :  data_out=8'hc9;   8'h35  :  data_out=8'h08;   8'h36  :  data_out=8'he8;   8'h37  :  data_out=8'h95;   
	8'h38  :  data_out=8'h80;   8'h39  :  data_out=8'hdf;   8'h3a  :  data_out=8'h94;   8'h3b  :  data_out=8'hfa;
	8'h3c  :  data_out=8'h75;   8'h3d  :  data_out=8'h8f;   8'h3e  :  data_out=8'h3f;   8'h3f  :  data_out=8'ha6;
	
	8'h40  :  data_out=8'h47;   8'h41  :  data_out=8'h07;   8'h42  :  data_out=8'ha7;   8'h43  :  data_out=8'hfc;   
	8'h44  :  data_out=8'hf3;   8'h45  :  data_out=8'h73;   8'h46  :  data_out=8'h17;   8'h47  :  data_out=8'hba;   
	8'h48  :  data_out=8'h83;   8'h49  :  data_out=8'h59;   8'h4a  :  data_out=8'h3c;   8'h4b  :  data_out=8'h19;
	8'h4c  :  data_out=8'he6;   8'h4d  :  data_out=8'h85;   8'h4e  :  data_out=8'h4f;   8'h4f  :  data_out=8'ha8;
	
	8'h50  :  data_out=8'h68;   8'h51  :  data_out=8'h6b;   8'h52  :  data_out=8'h81;   8'h53  :  data_out=8'hb2;   
	8'h54  :  data_out=8'h71;   8'h55  :  data_out=8'h64;   8'h56  :  data_out=8'hda;   8'h57  :  data_out=8'h8b;   
	8'h58  :  data_out=8'hf8;   8'h59  :  data_out=8'heb;   8'h5a  :  data_out=8'h0f;   8'h5b  :  data_out=8'h4b;
	8'h5c  :  data_out=8'h70;   8'h5d  :  data_out=8'h56;   8'h5e  :  data_out=8'h9d;   8'h5f  :  data_out=8'h35;
	
	8'h60  :  data_out=8'h1e;   8'h61  :  data_out=8'h24;   8'h62  :  data_out=8'h0e;   8'h63  :  data_out=8'h5e;   
	8'h64  :  data_out=8'h63;   8'h65  :  data_out=8'h58;   8'h66  :  data_out=8'hd1;   8'h67  :  data_out=8'ha2;   
	8'h68  :  data_out=8'h25;   8'h69  :  data_out=8'h22;   8'h6a  :  data_out=8'h7c;   8'h6b  :  data_out=8'h3b;
	8'h6c  :  data_out=8'h01;   8'h6d  :  data_out=8'h21;   8'h6e  :  data_out=8'h78;   8'h6f  :  data_out=8'h87;
	
	8'h70  :  data_out=8'hd4;   8'h71  :  data_out=8'h00;   8'h72  :  data_out=8'h46;   8'h73  :  data_out=8'h57;   
	8'h74  :  data_out=8'h9f;   8'h75  :  data_out=8'hd3;   8'h76  :  data_out=8'h27;   8'h77  :  data_out=8'h52;   
	8'h78  :  data_out=8'h4c;   8'h79  :  data_out=8'h36;   8'h7a  :  data_out=8'h02;   8'h7b  :  data_out=8'he7;
	8'h7c  :  data_out=8'ha0;   8'h7d  :  data_out=8'hc4;   8'h7e  :  data_out=8'hc8;   8'h7f  :  data_out=8'h9e;
	
	8'h80  :  data_out=8'hea;   8'h81  :  data_out=8'hbf;   8'h82  :  data_out=8'h8a;   8'h83  :  data_out=8'hd2;   
	8'h84  :  data_out=8'h40;   8'h85  :  data_out=8'hc7;   8'h86  :  data_out=8'h38;   8'h87  :  data_out=8'hb5;   
	8'h88  :  data_out=8'ha3;   8'h89  :  data_out=8'hf7;   8'h8a  :  data_out=8'hf2;   8'h8b  :  data_out=8'hce;
	8'h8c  :  data_out=8'hf9;   8'h8d  :  data_out=8'h61;   8'h8e  :  data_out=8'h15;   8'h8f  :  data_out=8'ha1;
	
	8'h90  :  data_out=8'he0;   8'h91  :  data_out=8'hae;   8'h92  :  data_out=8'h5d;   8'h93  :  data_out=8'ha4;   
	8'h94  :  data_out=8'h9b;   8'h95  :  data_out=8'h34;   8'h96  :  data_out=8'h1a;   8'h97  :  data_out=8'h55;   
	8'h98  :  data_out=8'had;   8'h99  :  data_out=8'h93;   8'h9a  :  data_out=8'h32;   8'h9b  :  data_out=8'h30;
	8'h9c  :  data_out=8'hf5;   8'h9d  :  data_out=8'h8c;   8'h9e  :  data_out=8'hb1;   8'h9f  :  data_out=8'he3;
	
	
	8'ha0  :  data_out=8'h1d;   8'ha1  :  data_out=8'hf6;   8'ha2  :  data_out=8'he2;   8'ha3  :  data_out=8'h2e;   
	8'ha4  :  data_out=8'h82;   8'ha5  :  data_out=8'h66;   8'ha6  :  data_out=8'hca;   8'ha7  :  data_out=8'h60;   
	8'ha8  :  data_out=8'hc0;   8'ha9  :  data_out=8'h29;   8'haa  :  data_out=8'h23;   8'hab  :  data_out=8'hab;
	8'hac  :  data_out=8'h0d;   8'had  :  data_out=8'h53;   8'hae  :  data_out=8'h4e;   8'haf  :  data_out=8'h6f;
	
	8'hb0  :  data_out=8'hd5;   8'hb1  :  data_out=8'hdb;   8'hb2  :  data_out=8'h37;   8'hb3  :  data_out=8'h45;   
	8'hb4  :  data_out=8'hde;   8'hb5  :  data_out=8'hfd;   8'hb6  :  data_out=8'h8e;   8'hb7  :  data_out=8'h2f;   
	8'hb8  :  data_out=8'h03;   8'hb9  :  data_out=8'hff;   8'hba  :  data_out=8'h6a;   8'hbb  :  data_out=8'h72;
	8'hbc  :  data_out=8'h6d;   8'hbd  :  data_out=8'h6c;   8'hbe  :  data_out=8'h5b;   8'hbf  :  data_out=8'h51;
	
	8'hc0  :  data_out=8'h8d;   8'hc1  :  data_out=8'h1b;   8'hc2  :  data_out=8'haf;   8'hc3  :  data_out=8'h92;   
	8'hc4  :  data_out=8'hbb;   8'hc5  :  data_out=8'hdd;   8'hc6  :  data_out=8'hbc;   8'hc7  :  data_out=8'h7f;   
	8'hc8  :  data_out=8'h11;   8'hc9  :  data_out=8'hd9;   8'hca  :  data_out=8'h5c;   8'hcb  :  data_out=8'h41;
	8'hcc  :  data_out=8'h1f;   8'hcd  :  data_out=8'h10;   8'hce  :  data_out=8'h5a;   8'hcf  :  data_out=8'hd8;
	
	8'hd0  :  data_out=8'h0a;   8'hd1  :  data_out=8'hc1;   8'hd2  :  data_out=8'h31;   8'hd3  :  data_out=8'h88;   
	8'hd4  :  data_out=8'ha5;   8'hd5  :  data_out=8'hcd;   8'hd6  :  data_out=8'h7b;   8'hd7  :  data_out=8'hbd;   
	8'hd8  :  data_out=8'h2d;   8'hd9  :  data_out=8'h74;   8'hda  :  data_out=8'hd0;   8'hdb  :  data_out=8'h12;
	8'hdc  :  data_out=8'hb8;   8'hdd  :  data_out=8'he5;   8'hde  :  data_out=8'hb4;   8'hdf  :  data_out=8'hb0;
	
	8'he0  :  data_out=8'h89;   8'he1  :  data_out=8'h69;   8'he2  :  data_out=8'h97;   8'he3  :  data_out=8'h4a;   
	8'he4  :  data_out=8'h0c;   8'he5  :  data_out=8'h96;   8'he6  :  data_out=8'h77;   8'he7  :  data_out=8'h7e;   
	8'he8  :  data_out=8'h65;   8'he9  :  data_out=8'hb9;   8'hea  :  data_out=8'hf1;   8'heb  :  data_out=8'h09;
	8'hec  :  data_out=8'hc5;   8'hed  :  data_out=8'h6e;   8'hee  :  data_out=8'hc6;   8'hef  :  data_out=8'h84;
	
	8'hf0  :  data_out=8'h18;   8'hf1  :  data_out=8'hf0;   8'hf2  :  data_out=8'h7d;   8'hf3  :  data_out=8'hec;   
	8'hf4  :  data_out=8'h3a;   8'hf5  :  data_out=8'hdc;   8'hf6  :  data_out=8'h4d;   8'hf7  :  data_out=8'h20;   
	8'hf8  :  data_out=8'h79;   8'hf9  :  data_out=8'hee;   8'hfa  :  data_out=8'h5f;   8'hfb  :  data_out=8'h3e;
	8'hfc  :  data_out=8'hd7;   8'hfd  :  data_out=8'hcb;   8'hfe  :  data_out=8'h39;   8'hff  :  data_out=8'h48;
  endcase

endmodule

