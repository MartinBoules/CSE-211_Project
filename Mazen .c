char UART_InChar(void)
{
	char data;
	while ( (UART5_FR_R & 0x00000010) != 0 ){} // RXFE Flag !=0 -> wait (wait until full)
	data = UART5_DR_R & 0xFF ; // Data are located from 0-7 bits in DR_R (basmagaaaaa)
	return data;
}
uint16_t char_to_int(char a){
	uint16_t x;
  x = (a)- 48;
	return x;
}
float Angle_Conv(uint8_t degree, float min)
{
	float angle;
	angle = degree + (min / 60);
	return angle;
}