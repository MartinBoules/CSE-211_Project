// To take out each digit on its own :
// if num has 1 digit => units = num , ex: num = 5 -> units = 5
// if num has 2 digits => units = num % 10 , tens = (num - units) /10 , ex: num = 46 -> units = 6 , tens = 4
// if num has 3 digits => x = num % 100 , units = x % 10 , tens = (x - units) / 10 , hundreds = (num - tens) / 100 , ex: num = 108 -> units = 8 , tens = 0 , hundreds = 1


// first if condition
		if (dist >=0 && dist <= 9) 
		{
			switch (dist) {
				case 0 : GPIO_PORTB_DATA_R |= 0x00;
			break ;
				case 1 : GPIO_PORTB_DATA_R |= 0x01;
			break ;
				case 2 : GPIO_PORTB_DATA_R |= 0x02;
			break ;
				case 3 : GPIO_PORTB_DATA_R |= 0x03;
			break ;
				case 4 : GPIO_PORTB_DATA_R |= 0x04;
			break ;
				case 5 : GPIO_PORTB_DATA_R |= 0x05;
			break ;
				case 6 : GPIO_PORTB_DATA_R |= 0x06;
			break ;
				case 7 : GPIO_PORTB_DATA_R |= 0x07;
			break ;
				case 8 : GPIO_PORTB_DATA_R |= 0x08;
			break ;
				case 9 : GPIO_PORTB_DATA_R |= 0x09;
			break ;
		}
		}

// Second if condition
		if (dist >9 && dist <= 99) 
		{
			switch (x) {
				case 0 : GPIO_PORTB_DATA_R |= 0x00;
			break ;
				case 1 : GPIO_PORTB_DATA_R |= 0x10;
			break ;
				case 2 : GPIO_PORTB_DATA_R |= 0x20;
			break ;
				case 3 : GPIO_PORTB_DATA_R |= 0x30;
			break ;
				case 4 : GPIO_PORTB_DATA_R |= 0x40;
			break ;
				case 5 : GPIO_PORTB_DATA_R |= 0x50;
			break ;
				case 6 : GPIO_PORTB_DATA_R |= 0x60;
			break ;
				case 7 : GPIO_PORTB_DATA_R |= 0x70;
			break ;
				case 8 : GPIO_PORTB_DATA_R |= 0x80;
			break ;
				case 9 : GPIO_PORTB_DATA_R |= 0x90;
			break ;
			}
		}	

// Complete code without decoder to get the number on 7* segment
	switch (hundreds)
		{
				case 0 : GPIO_PORTB_DATA_R |= 0x3F;
			break ;
				case 1 : GPIO_PORTB_DATA_R |= 0x06;
			break ;
				case 2 : GPIO_PORTB_DATA_R |= 0x5B;
			break ;
				case 3 : GPIO_PORTB_DATA_R |= 0x4F;
			break ;
				case 4 : GPIO_PORTB_DATA_R |= 0x66;
			break ;
				case 5 : GPIO_PORTB_DATA_R |= 0x6D;
			break ;
				case 6 : GPIO_PORTB_DATA_R |= 0x7D;
			break ;
				case 7 : GPIO_PORTB_DATA_R |= 0x07;
			break ;
				case 8 : GPIO_PORTB_DATA_R |= 0x7F;
			break ;
				case 9 : GPIO_PORTB_DATA_R |= 0x6F;
			break ;
		}