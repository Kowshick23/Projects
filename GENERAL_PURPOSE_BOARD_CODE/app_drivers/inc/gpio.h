#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "../../app_drivers/inc/common.h"

/*********digital output*******/
#define GPIO_BOARD_3_CH_1						GPIOE,GPIO_PIN_0
#define GPIO_BOARD_3_CH_2						GPIOE,GPIO_PIN_1
#define GPIO_BOARD_3_CH_3						GPIOE,GPIO_PIN_2
#define GPIO_BOARD_3_CH_4						GPIOE,GPIO_PIN_3
#define GPIO_BOARD_3_CH_5						GPIOE,GPIO_PIN_4
#define GPIO_BOARD_3_CH_6						GPIOE,GPIO_PIN_5
#define GPIO_BOARD_3_CH_7						GPIOE,GPIO_PIN_6
#define GPIO_BOARD_3_CH_8						GPIOE,GPIO_PIN_7
#define GPIO_BOARD_3_CH_9						GPIOE,GPIO_PIN_8
#define GPIO_BOARD_3_CH_10						GPIOE,GPIO_PIN_9
#define GPIO_BOARD_3_CH_11						GPIOE,GPIO_PIN_10
#define GPIO_BOARD_3_CH_12						GPIOE,GPIO_PIN_11
#define GPIO_BOARD_3_CH_13						GPIOE,GPIO_PIN_12
#define GPIO_BOARD_3_CH_14						GPIOE,GPIO_PIN_13
#define GPIO_BOARD_3_CH_15						GPIOE,GPIO_PIN_14
#define GPIO_BOARD_3_CH_16						GPIOE,GPIO_PIN_15


#define GPIO_BOARD_1_CH_1						GPIOA,GPIO_PIN_8
#define GPIO_BOARD_1_CH_2						GPIOA,GPIO_PIN_9
#define GPIO_BOARD_1_CH_3						GPIOA,GPIO_PIN_11
#define GPIO_BOARD_1_CH_4						GPIOB,GPIO_PIN_4
#define GPIO_BOARD_1_CH_5						GPIOB,GPIO_PIN_5
#define GPIO_BOARD_1_CH_6						GPIOB,GPIO_PIN_6
#define GPIO_BOARD_1_CH_7						GPIOC,GPIO_PIN_7
#define GPIO_BOARD_1_CH_8						GPIOC,GPIO_PIN_8
#define GPIO_BOARD_1_CH_9						GPIOC,GPIO_PIN_9
#define GPIO_BOARD_1_CH_10						GPIOC,GPIO_PIN_10
#define GPIO_BOARD_1_CH_11						GPIOC,GPIO_PIN_11
#define GPIO_BOARD_1_CH_12						GPIOC,GPIO_PIN_12
#define GPIO_BOARD_1_CH_13						GPIOD,GPIO_PIN_2
#define GPIO_BOARD_1_CH_14						GPIOD,GPIO_PIN_3
#define GPIO_BOARD_1_CH_15						GPIOD,GPIO_PIN_5
#define GPIO_BOARD_1_CH_16						GPIOD,GPIO_PIN_6

#define GPIO_BOARD_2_CH_1						GPIOD,GPIO_PIN_7
#define GPIO_BOARD_2_CH_2						GPIOD,GPIO_PIN_14
#define GPIO_BOARD_2_CH_3						GPIOD,GPIO_PIN_15
#define GPIO_BOARD_2_CH_4						GPIOF,GPIO_PIN_6
#define GPIO_BOARD_2_CH_5						GPIOF,GPIO_PIN_7
#define GPIO_BOARD_2_CH_6						GPIOF,GPIO_PIN_8
#define GPIO_BOARD_2_CH_7						GPIOG,GPIO_PIN_1
#define GPIO_BOARD_2_CH_8						GPIOG,GPIO_PIN_2
#define GPIO_BOARD_2_CH_9						GPIOG,GPIO_PIN_3
#define GPIO_BOARD_2_CH_10						GPIOG,GPIO_PIN_4
#define GPIO_BOARD_2_CH_11						GPIOG,GPIO_PIN_5
#define GPIO_BOARD_2_CH_12						GPIOG,GPIO_PIN_8
#define GPIO_BOARD_2_CH_13						GPIOG,GPIO_PIN_9
#define GPIO_BOARD_2_CH_14						GPIOG,GPIO_PIN_14
#define GPIO_BOARD_2_CH_15						GPIOG,GPIO_PIN_15
#define GPIO_BOARD_2_CH_16						GPIOH,GPIO_PIN_2


/***************************outputs functions********/
#define	 x

#define	 write_gpio_board_1_ch_1(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_1,x)
#define	 write_gpio_board_1_ch_2(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_2,x)
#define	 write_gpio_board_1_ch_3(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_3,x)
#define	 write_gpio_board_1_ch_4(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_4,x)
#define	 write_gpio_board_1_ch_5(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_5,x)
#define	 write_gpio_board_1_ch_6(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_6,x)
#define	 write_gpio_board_1_ch_7(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_7,x)
#define	 write_gpio_board_1_ch_8(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_8,x)
#define	 write_gpio_board_1_ch_9(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_9,x)
#define	 write_gpio_board_1_ch_10(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_10,x)
#define	 write_gpio_board_1_ch_11(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_11,x)
#define	 write_gpio_board_1_ch_12(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_12,x)
#define	 write_gpio_board_1_ch_13(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_13,x)
#define	 write_gpio_board_1_ch_14(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_14,x)
#define	 write_gpio_board_1_ch_15(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_15,x)
#define	 write_gpio_board_1_ch_16(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_1_CH_16,x)

#define	 write_gpio_board_2_ch_1(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_1,x)
#define	 write_gpio_board_2_ch_2(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_2,x)
#define	 write_gpio_board_2_ch_3(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_3,x)
#define	 write_gpio_board_2_ch_4(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_4,x)
#define	 write_gpio_board_2_ch_5(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_5,x)
#define	 write_gpio_board_2_ch_6(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_6,x)
#define	 write_gpio_board_2_ch_7(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_7,x)
#define	 write_gpio_board_2_ch_8(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_8,x)
#define	 write_gpio_board_2_ch_9(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_9,x)
#define	 write_gpio_board_2_ch_10(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_10,x)
#define	 write_gpio_board_2_ch_11(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_11,x)
#define	 write_gpio_board_2_ch_12(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_12,x)
#define	 write_gpio_board_2_ch_13(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_13,x)
#define	 write_gpio_board_2_ch_14(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_14,x)
#define	 write_gpio_board_2_ch_15(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_15,x)
#define	 write_gpio_board_2_ch_16(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_2_CH_16,x)

#define	 write_gpio_board_3_ch_1(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_1,x)
#define	 write_gpio_board_3_ch_2(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_2,x)
#define	 write_gpio_board_3_ch_3(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_3,x)
#define	 write_gpio_board_3_ch_4(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_4,x)
#define	 write_gpio_board_3_ch_5(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_5,x)
#define	 write_gpio_board_3_ch_6(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_6,x)
#define	 write_gpio_board_3_ch_7(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_7,x)
#define	 write_gpio_board_3_ch_8(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_8,x)
#define	 write_gpio_board_3_ch_9(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_9,x)
#define	 write_gpio_board_3_ch_10(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_10,x)
#define	 write_gpio_board_3_ch_11(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_11,x)
#define	 write_gpio_board_3_ch_12(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_12,x)
#define	 write_gpio_board_3_ch_13(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_13,x)
#define	 write_gpio_board_3_ch_14(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_14,x)
#define	 write_gpio_board_3_ch_15(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_15,x)
#define	 write_gpio_board_3_ch_16(x)     		        HAL_GPIO_WritePin(GPIO_BOARD_3_CH_16,x)

void gpio_init (void);

#endif /* INC_GPIO_H_ */
