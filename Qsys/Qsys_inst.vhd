	component Qsys is
		port (
			adc_ltc2308_0_conduit_end_CONVST     : out   std_logic;                                       -- CONVST
			adc_ltc2308_0_conduit_end_SCK        : out   std_logic;                                       -- SCK
			adc_ltc2308_0_conduit_end_SDI        : out   std_logic;                                       -- SDI
			adc_ltc2308_0_conduit_end_SDO        : in    std_logic                    := 'X';             -- SDO
			clk_clk                              : in    std_logic                    := 'X';             -- clk
			dc_motor_left_conduit_end_motor_in1  : out   std_logic;                                       -- motor_in1
			dc_motor_left_conduit_end_motor_in2  : out   std_logic;                                       -- motor_in2
			dc_motor_left_conduit_end_pwm        : out   std_logic;                                       -- pwm
			dc_motor_right_conduit_end_motor_in1 : out   std_logic;                                       -- motor_in1
			dc_motor_right_conduit_end_motor_in2 : out   std_logic;                                       -- motor_in2
			dc_motor_right_conduit_end_pwm       : out   std_logic;                                       -- pwm
			esp32_io_external_connection_export  : in    std_logic_vector(2 downto 0) := (others => 'X'); -- export
			ir_rx_conduit_end_export             : in    std_logic                    := 'X';             -- export
			led_external_connection_export       : out   std_logic_vector(7 downto 0);                    -- export
			motor_measure_left_conduit_end_ab    : in    std_logic_vector(1 downto 0) := (others => 'X'); -- ab
			motor_measure_right_conduit_end_ab   : in    std_logic_vector(1 downto 0) := (others => 'X'); -- ab
			mpu_i2c_export_scl_pad_io            : inout std_logic                    := 'X';             -- scl_pad_io
			mpu_i2c_export_sda_pad_io            : inout std_logic                    := 'X';             -- sda_pad_io
			mpu_int_external_connection_export   : in    std_logic                    := 'X';             -- export
			reset_reset_n                        : in    std_logic                    := 'X';             -- reset_n
			sonic_distance_0_conduit_end_echo    : in    std_logic                    := 'X';             -- echo
			sonic_distance_0_conduit_end_trigger : out   std_logic;                                       -- trigger
			sw_external_connection_export        : in    std_logic_vector(3 downto 0) := (others => 'X'); -- export
			uart_bt_external_interface_RXD       : in    std_logic                    := 'X';             -- RXD
			uart_bt_external_interface_TXD       : out   std_logic                                        -- TXD
		);
	end component Qsys;

	u0 : component Qsys
		port map (
			adc_ltc2308_0_conduit_end_CONVST     => CONNECTED_TO_adc_ltc2308_0_conduit_end_CONVST,     --       adc_ltc2308_0_conduit_end.CONVST
			adc_ltc2308_0_conduit_end_SCK        => CONNECTED_TO_adc_ltc2308_0_conduit_end_SCK,        --                                .SCK
			adc_ltc2308_0_conduit_end_SDI        => CONNECTED_TO_adc_ltc2308_0_conduit_end_SDI,        --                                .SDI
			adc_ltc2308_0_conduit_end_SDO        => CONNECTED_TO_adc_ltc2308_0_conduit_end_SDO,        --                                .SDO
			clk_clk                              => CONNECTED_TO_clk_clk,                              --                             clk.clk
			dc_motor_left_conduit_end_motor_in1  => CONNECTED_TO_dc_motor_left_conduit_end_motor_in1,  --       dc_motor_left_conduit_end.motor_in1
			dc_motor_left_conduit_end_motor_in2  => CONNECTED_TO_dc_motor_left_conduit_end_motor_in2,  --                                .motor_in2
			dc_motor_left_conduit_end_pwm        => CONNECTED_TO_dc_motor_left_conduit_end_pwm,        --                                .pwm
			dc_motor_right_conduit_end_motor_in1 => CONNECTED_TO_dc_motor_right_conduit_end_motor_in1, --      dc_motor_right_conduit_end.motor_in1
			dc_motor_right_conduit_end_motor_in2 => CONNECTED_TO_dc_motor_right_conduit_end_motor_in2, --                                .motor_in2
			dc_motor_right_conduit_end_pwm       => CONNECTED_TO_dc_motor_right_conduit_end_pwm,       --                                .pwm
			esp32_io_external_connection_export  => CONNECTED_TO_esp32_io_external_connection_export,  --    esp32_io_external_connection.export
			ir_rx_conduit_end_export             => CONNECTED_TO_ir_rx_conduit_end_export,             --               ir_rx_conduit_end.export
			led_external_connection_export       => CONNECTED_TO_led_external_connection_export,       --         led_external_connection.export
			motor_measure_left_conduit_end_ab    => CONNECTED_TO_motor_measure_left_conduit_end_ab,    --  motor_measure_left_conduit_end.ab
			motor_measure_right_conduit_end_ab   => CONNECTED_TO_motor_measure_right_conduit_end_ab,   -- motor_measure_right_conduit_end.ab
			mpu_i2c_export_scl_pad_io            => CONNECTED_TO_mpu_i2c_export_scl_pad_io,            --                  mpu_i2c_export.scl_pad_io
			mpu_i2c_export_sda_pad_io            => CONNECTED_TO_mpu_i2c_export_sda_pad_io,            --                                .sda_pad_io
			mpu_int_external_connection_export   => CONNECTED_TO_mpu_int_external_connection_export,   --     mpu_int_external_connection.export
			reset_reset_n                        => CONNECTED_TO_reset_reset_n,                        --                           reset.reset_n
			sonic_distance_0_conduit_end_echo    => CONNECTED_TO_sonic_distance_0_conduit_end_echo,    --    sonic_distance_0_conduit_end.echo
			sonic_distance_0_conduit_end_trigger => CONNECTED_TO_sonic_distance_0_conduit_end_trigger, --                                .trigger
			sw_external_connection_export        => CONNECTED_TO_sw_external_connection_export,        --          sw_external_connection.export
			uart_bt_external_interface_RXD       => CONNECTED_TO_uart_bt_external_interface_RXD,       --      uart_bt_external_interface.RXD
			uart_bt_external_interface_TXD       => CONNECTED_TO_uart_bt_external_interface_TXD        --                                .TXD
		);

