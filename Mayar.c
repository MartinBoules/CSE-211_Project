void UART5_Init(void) 
{
	SYSCTL_RCGCUART_R |= 0x20; // Enable UART 5
	SYSCTL_RCGCGPIO_R |= 0x10; //enable the clock for ports A,B,E,F
	while ((SYSCTL_PRGPIO_R&0x10) == 0){}
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x30; // to control pin 4&5 in port E
	GPIO_PORTE_DEN_R |= 0x30; // digital enable for pins 4&5 in port E
	GPIO_PORTE_AMSEL_R &= (~0x30); // NO analog I/O
	GPIO_PORTE_AFSEL_R |= 0x30; // Alt Function for Pins 4,5
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&(~0x00FF0000)) + 0x00110000; //PCTL(&E4) | 0x00010000
	UART5_CTL_R &= ~(0x01); // disable UART5 at first to config
	UART5_IBRD_R = 104;
	UART5_FBRD_R = 11;
	UART5_LCRH_R |= 0x70; // word length = 8-bits , FIFO_EN = 1
	UART5_CTL_R |= 0x301; // UART enable , Rx Enable
}