// Part 1
while((GPIO_PORTF_DATA_R&0x10)!=0){	
	for (i=0 ; i<100 ; i++ ){
			character=UART_InChar();
		  y[i]=character;
			if (y[i]=='$'&& i!=0) {
			break;
			}	
		}
	if (y[2] == 'G'&&y[3] == 'L'&&y[4] == 'L'){
		comma = 0;
			for (i = 0; i < 100; i++){
				if (y[i] == ','){
					comma = comma + 1;
					if (comma == 1){
						
						lat2_ten = char_to_int(y[i+ 1]);
						lat2_ten = 10 * lat2_ten;
						lat2_units = char_to_int(y[i + 2]);
						lat2_degree = lat2_ten + lat2_units;
						lat2_ten = char_to_int(y[i + 3]);
						lat2_ten = 10 * lat2_ten;
						lat2_units = char_to_int(y[i + 4]);
						lat2_minute = lat2_ten + lat2_units;
						p = 0;
						for (k = i + 6; k < 50; k++) {
							if (y[k] != ',') {
								 dec = char_to_int(y[k]);
								Ten_pow = pow(10, p = p - 1);
								lat2_minute += (dec*Ten_pow);
							}
							else break;
						}
					}
				}
			}
	}