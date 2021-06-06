void Init (void)
{
SYSCTL_RCGCGPIO_R |= 0x23; //enable the clock for ports A,B,F
while ((SYSCTL_PRGPIO_R&0x23) == 0){} //To get an acknowledgement that the required ports has been activated.
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R |= 0x1E; // to control pins 1,2,3,4 in port F
GPIO_PORTF_DIR_R |= 0x0E; // output for pins 1,2,3 
GPIO_PORTF_DEN_R |= 0x1E; // ditgal for pins 1,2,3,4
GPIO_PORTF_AMSEL_R &= (~0x1E); // NO analog IO
GPIO_PORTF_AFSEL_R &=(~0x1E); // make it default for pins all pins (GPIO)
GPIO_PORTF_PCTL_R &= (~0xFFFF0); 
GPIO_PORTF_PUR_R|= 0x10; // connect internal resistance with pin 4 
GPIO_PORTF_DATA_R &= (~0x0E); // initialize the data = 0
GPIO_PORTA_LOCK_R = 0x4C4F434B;
GPIO_PORTA_CR_R |= 0x3C; // to control pins 2,3,4,5 in port A
GPIO_PORTA_DIR_R |= 0x3C; // all pins are outputs
GPIO_PORTA_DEN_R |= 0x3C; // all pins are digital
GPIO_PORTA_AMSEL_R &= (~0x3C); // No analog IO
GPIO_PORTA_AFSEL_R &= (~0x3C); // make it default for pins all pins (GPIO)
GPIO_PORTA_PCTL_R &= (~0x00FFFF00);
GPIO_PORTA_DATA_R &= (~0x3C); // initialize the data = 0
GPIO_PORTB_LOCK_R = 0x4C4F434B;
GPIO_PORTB_CR_R |= 0xFF; // to control all pins in port B
GPIO_PORTB_DIR_R |= 0xFF; // all pins are outputs
GPIO_PORTB_DEN_R |= 0xFF; // all pins are digital
GPIO_PORTB_AMSEL_R &= (~0xFF); // No analog IO
GPIO_PORTB_AFSEL_R &=(~0xFF); // make it default for pins all pins (GPIO)
GPIO_PORTB_PCTL_R &= (~0xFFFFFFFF);
GPIO_PORTB_DATA_R &= (~0xFF); // initialize the data = 0
}