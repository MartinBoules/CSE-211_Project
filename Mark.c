
//Part 2
if (comma == 3){
						
						long2_ten = char_to_int(y[i+ 2]);
						long2_ten = 10 * long2_ten;
						long2_units = char_to_int(y[i + 3]);
						long2_degree = long2_ten + long2_units;
						long2_ten = char_to_int(y[i+ 4]);
						long2_ten = 10 * long2_ten;
						long2_units = char_to_int(y[i + 5]);
						long2_minute = long2_ten + long2_units;
						p = 0;
						for (k = i + 7; k < 50; k++) {
							if (y[k] != ',') {
								dec = char_to_int(y[k]);
								Ten_pow = pow(10, p = p - 1);
								long2_minute += (dec*Ten_pow);
							}
							else break;
						}
					}
if (comma == 6){
			if (y[i + 1] == 'A')
							{
							// CODEEEEE
							}
				}
				