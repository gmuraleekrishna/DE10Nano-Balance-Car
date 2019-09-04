// Qsys_mm_interconnect_0.v

// This file was auto-generated from altera_mm_interconnect_hw.tcl.  If you edit it your changes
// will probably be lost.
// 
// Generated using ACDS version 18.1 625

`timescale 1 ps / 1 ps
module Qsys_mm_interconnect_0 (
		input  wire        clk_0_clk_clk,                                     //                                   clk_0_clk.clk
		input  wire        motor_run_right_reset_reset_bridge_in_reset_reset, // motor_run_right_reset_reset_bridge_in_reset.reset
		input  wire [3:0]  motor_run_right_avalon_master_address,             //               motor_run_right_avalon_master.address
		output wire        motor_run_right_avalon_master_waitrequest,         //                                            .waitrequest
		input  wire        motor_run_right_avalon_master_chipselect,          //                                            .chipselect
		input  wire        motor_run_right_avalon_master_write,               //                                            .write
		input  wire [31:0] motor_run_right_avalon_master_writedata,           //                                            .writedata
		output wire [1:0]  dc_motor_right_avalon_slave_address,               //                 dc_motor_right_avalon_slave.address
		output wire        dc_motor_right_avalon_slave_write,                 //                                            .write
		output wire        dc_motor_right_avalon_slave_read,                  //                                            .read
		input  wire [31:0] dc_motor_right_avalon_slave_readdata,              //                                            .readdata
		output wire [31:0] dc_motor_right_avalon_slave_writedata,             //                                            .writedata
		output wire        dc_motor_right_avalon_slave_chipselect             //                                            .chipselect
	);

	wire         motor_run_right_avalon_master_translator_avalon_universal_master_0_waitrequest;   // dc_motor_right_avalon_slave_translator:uav_waitrequest -> motor_run_right_avalon_master_translator:uav_waitrequest
	wire  [31:0] motor_run_right_avalon_master_translator_avalon_universal_master_0_readdata;      // dc_motor_right_avalon_slave_translator:uav_readdata -> motor_run_right_avalon_master_translator:uav_readdata
	wire         motor_run_right_avalon_master_translator_avalon_universal_master_0_debugaccess;   // motor_run_right_avalon_master_translator:uav_debugaccess -> dc_motor_right_avalon_slave_translator:uav_debugaccess
	wire   [3:0] motor_run_right_avalon_master_translator_avalon_universal_master_0_address;       // motor_run_right_avalon_master_translator:uav_address -> dc_motor_right_avalon_slave_translator:uav_address
	wire         motor_run_right_avalon_master_translator_avalon_universal_master_0_read;          // motor_run_right_avalon_master_translator:uav_read -> dc_motor_right_avalon_slave_translator:uav_read
	wire   [3:0] motor_run_right_avalon_master_translator_avalon_universal_master_0_byteenable;    // motor_run_right_avalon_master_translator:uav_byteenable -> dc_motor_right_avalon_slave_translator:uav_byteenable
	wire         motor_run_right_avalon_master_translator_avalon_universal_master_0_readdatavalid; // dc_motor_right_avalon_slave_translator:uav_readdatavalid -> motor_run_right_avalon_master_translator:uav_readdatavalid
	wire         motor_run_right_avalon_master_translator_avalon_universal_master_0_lock;          // motor_run_right_avalon_master_translator:uav_lock -> dc_motor_right_avalon_slave_translator:uav_lock
	wire         motor_run_right_avalon_master_translator_avalon_universal_master_0_write;         // motor_run_right_avalon_master_translator:uav_write -> dc_motor_right_avalon_slave_translator:uav_write
	wire  [31:0] motor_run_right_avalon_master_translator_avalon_universal_master_0_writedata;     // motor_run_right_avalon_master_translator:uav_writedata -> dc_motor_right_avalon_slave_translator:uav_writedata
	wire   [2:0] motor_run_right_avalon_master_translator_avalon_universal_master_0_burstcount;    // motor_run_right_avalon_master_translator:uav_burstcount -> dc_motor_right_avalon_slave_translator:uav_burstcount

	altera_merlin_master_translator #(
		.AV_ADDRESS_W                (4),
		.AV_DATA_W                   (32),
		.AV_BURSTCOUNT_W             (1),
		.AV_BYTEENABLE_W             (4),
		.UAV_ADDRESS_W               (4),
		.UAV_BURSTCOUNT_W            (3),
		.USE_READ                    (0),
		.USE_WRITE                   (1),
		.USE_BEGINBURSTTRANSFER      (0),
		.USE_BEGINTRANSFER           (0),
		.USE_CHIPSELECT              (1),
		.USE_BURSTCOUNT              (0),
		.USE_READDATAVALID           (0),
		.USE_WAITREQUEST             (1),
		.USE_READRESPONSE            (0),
		.USE_WRITERESPONSE           (0),
		.AV_SYMBOLS_PER_WORD         (4),
		.AV_ADDRESS_SYMBOLS          (1),
		.AV_BURSTCOUNT_SYMBOLS       (0),
		.AV_CONSTANT_BURST_BEHAVIOR  (0),
		.UAV_CONSTANT_BURST_BEHAVIOR (0),
		.AV_LINEWRAPBURSTS           (0),
		.AV_REGISTERINCOMINGSIGNALS  (0)
	) motor_run_right_avalon_master_translator (
		.clk                    (clk_0_clk_clk),                                                                    //                       clk.clk
		.reset                  (motor_run_right_reset_reset_bridge_in_reset_reset),                                //                     reset.reset
		.uav_address            (motor_run_right_avalon_master_translator_avalon_universal_master_0_address),       // avalon_universal_master_0.address
		.uav_burstcount         (motor_run_right_avalon_master_translator_avalon_universal_master_0_burstcount),    //                          .burstcount
		.uav_read               (motor_run_right_avalon_master_translator_avalon_universal_master_0_read),          //                          .read
		.uav_write              (motor_run_right_avalon_master_translator_avalon_universal_master_0_write),         //                          .write
		.uav_waitrequest        (motor_run_right_avalon_master_translator_avalon_universal_master_0_waitrequest),   //                          .waitrequest
		.uav_readdatavalid      (motor_run_right_avalon_master_translator_avalon_universal_master_0_readdatavalid), //                          .readdatavalid
		.uav_byteenable         (motor_run_right_avalon_master_translator_avalon_universal_master_0_byteenable),    //                          .byteenable
		.uav_readdata           (motor_run_right_avalon_master_translator_avalon_universal_master_0_readdata),      //                          .readdata
		.uav_writedata          (motor_run_right_avalon_master_translator_avalon_universal_master_0_writedata),     //                          .writedata
		.uav_lock               (motor_run_right_avalon_master_translator_avalon_universal_master_0_lock),          //                          .lock
		.uav_debugaccess        (motor_run_right_avalon_master_translator_avalon_universal_master_0_debugaccess),   //                          .debugaccess
		.av_address             (motor_run_right_avalon_master_address),                                            //      avalon_anti_master_0.address
		.av_waitrequest         (motor_run_right_avalon_master_waitrequest),                                        //                          .waitrequest
		.av_chipselect          (motor_run_right_avalon_master_chipselect),                                         //                          .chipselect
		.av_write               (motor_run_right_avalon_master_write),                                              //                          .write
		.av_writedata           (motor_run_right_avalon_master_writedata),                                          //                          .writedata
		.av_burstcount          (1'b1),                                                                             //               (terminated)
		.av_byteenable          (4'b1111),                                                                          //               (terminated)
		.av_beginbursttransfer  (1'b0),                                                                             //               (terminated)
		.av_begintransfer       (1'b0),                                                                             //               (terminated)
		.av_read                (1'b0),                                                                             //               (terminated)
		.av_readdata            (),                                                                                 //               (terminated)
		.av_readdatavalid       (),                                                                                 //               (terminated)
		.av_lock                (1'b0),                                                                             //               (terminated)
		.av_debugaccess         (1'b0),                                                                             //               (terminated)
		.uav_clken              (),                                                                                 //               (terminated)
		.av_clken               (1'b1),                                                                             //               (terminated)
		.uav_response           (2'b00),                                                                            //               (terminated)
		.av_response            (),                                                                                 //               (terminated)
		.uav_writeresponsevalid (1'b0),                                                                             //               (terminated)
		.av_writeresponsevalid  ()                                                                                  //               (terminated)
	);

	altera_merlin_slave_translator #(
		.AV_ADDRESS_W                   (2),
		.AV_DATA_W                      (32),
		.UAV_DATA_W                     (32),
		.AV_BURSTCOUNT_W                (1),
		.AV_BYTEENABLE_W                (4),
		.UAV_BYTEENABLE_W               (4),
		.UAV_ADDRESS_W                  (4),
		.UAV_BURSTCOUNT_W               (3),
		.AV_READLATENCY                 (0),
		.USE_READDATAVALID              (0),
		.USE_WAITREQUEST                (0),
		.USE_UAV_CLKEN                  (0),
		.USE_READRESPONSE               (0),
		.USE_WRITERESPONSE              (0),
		.AV_SYMBOLS_PER_WORD            (4),
		.AV_ADDRESS_SYMBOLS             (0),
		.AV_BURSTCOUNT_SYMBOLS          (0),
		.AV_CONSTANT_BURST_BEHAVIOR     (0),
		.UAV_CONSTANT_BURST_BEHAVIOR    (0),
		.AV_REQUIRE_UNALIGNED_ADDRESSES (0),
		.CHIPSELECT_THROUGH_READLATENCY (0),
		.AV_READ_WAIT_CYCLES            (1),
		.AV_WRITE_WAIT_CYCLES           (0),
		.AV_SETUP_WAIT_CYCLES           (0),
		.AV_DATA_HOLD_CYCLES            (0)
	) dc_motor_right_avalon_slave_translator (
		.clk                    (clk_0_clk_clk),                                                                    //                      clk.clk
		.reset                  (motor_run_right_reset_reset_bridge_in_reset_reset),                                //                    reset.reset
		.uav_address            (motor_run_right_avalon_master_translator_avalon_universal_master_0_address),       // avalon_universal_slave_0.address
		.uav_burstcount         (motor_run_right_avalon_master_translator_avalon_universal_master_0_burstcount),    //                         .burstcount
		.uav_read               (motor_run_right_avalon_master_translator_avalon_universal_master_0_read),          //                         .read
		.uav_write              (motor_run_right_avalon_master_translator_avalon_universal_master_0_write),         //                         .write
		.uav_waitrequest        (motor_run_right_avalon_master_translator_avalon_universal_master_0_waitrequest),   //                         .waitrequest
		.uav_readdatavalid      (motor_run_right_avalon_master_translator_avalon_universal_master_0_readdatavalid), //                         .readdatavalid
		.uav_byteenable         (motor_run_right_avalon_master_translator_avalon_universal_master_0_byteenable),    //                         .byteenable
		.uav_readdata           (motor_run_right_avalon_master_translator_avalon_universal_master_0_readdata),      //                         .readdata
		.uav_writedata          (motor_run_right_avalon_master_translator_avalon_universal_master_0_writedata),     //                         .writedata
		.uav_lock               (motor_run_right_avalon_master_translator_avalon_universal_master_0_lock),          //                         .lock
		.uav_debugaccess        (motor_run_right_avalon_master_translator_avalon_universal_master_0_debugaccess),   //                         .debugaccess
		.av_address             (dc_motor_right_avalon_slave_address),                                              //      avalon_anti_slave_0.address
		.av_write               (dc_motor_right_avalon_slave_write),                                                //                         .write
		.av_read                (dc_motor_right_avalon_slave_read),                                                 //                         .read
		.av_readdata            (dc_motor_right_avalon_slave_readdata),                                             //                         .readdata
		.av_writedata           (dc_motor_right_avalon_slave_writedata),                                            //                         .writedata
		.av_chipselect          (dc_motor_right_avalon_slave_chipselect),                                           //                         .chipselect
		.av_begintransfer       (),                                                                                 //              (terminated)
		.av_beginbursttransfer  (),                                                                                 //              (terminated)
		.av_burstcount          (),                                                                                 //              (terminated)
		.av_byteenable          (),                                                                                 //              (terminated)
		.av_readdatavalid       (1'b0),                                                                             //              (terminated)
		.av_waitrequest         (1'b0),                                                                             //              (terminated)
		.av_writebyteenable     (),                                                                                 //              (terminated)
		.av_lock                (),                                                                                 //              (terminated)
		.av_clken               (),                                                                                 //              (terminated)
		.uav_clken              (1'b0),                                                                             //              (terminated)
		.av_debugaccess         (),                                                                                 //              (terminated)
		.av_outputenable        (),                                                                                 //              (terminated)
		.uav_response           (),                                                                                 //              (terminated)
		.av_response            (2'b00),                                                                            //              (terminated)
		.uav_writeresponsevalid (),                                                                                 //              (terminated)
		.av_writeresponsevalid  (1'b0)                                                                              //              (terminated)
	);

endmodule
