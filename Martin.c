				// CODEEE
							 lat2 = Angle_Conv(lat2_degree, lat2_minute);
					    	 long2 = Angle_Conv(long2_degree, long2_minute);
							 dist_2_points = distance_between_2_points(lat1,long1,lat2,long2);
							 dist += dist_2_points;
							 GPIO_PORTB_DATA_R &= 0x00;
								if (dist >=0 && dist <= 9) // in this case we will use the units 7-segment only
									{
										GPIO_PORTA_DATA_R &= (~0x04); // tens 7 - segment enabler ==> 0 , tens 7-segments are off
										GPIO_PORTA_DATA_R &= (~0x08); // hundreds 7 - segment enabler ==> 0 , hundreds 7-segments are off
										units_7segments_output(dist);
									}
								else if (dist > 9 && dist <= 99 ) // in this case we will use the units & tens 7-segments , hundreds 7-segment will not be used
								{
									GPIO_PORTA_DATA_R &= (~0x08); // hundreds 7 - segment enabler ==> 0 , hundreds 7-segments are off
									units = (int) dist % 10 ; // units = the value of units of dist
									units_7segments_output(units);
									tens = ((int)dist-units)/10 ; // tens = the value of tens of dist
									GPIO_PORTA_DATA_R |= 0x04; // tens 7 - segment enabler
									tens_7segments_output(tens);
								}
								else if (dist > 99 && dist <= 999 )
								{
									h = (int)dist % 100 ; 
									units = h % 10; // units = the value of units of dist
									units_7segments_output(units);
									tens = (h-units)/10 ; // tens = the value of tens of dist
									GPIO_PORTA_DATA_R |= 0x04; // tens 7 - segment enabler
									tens_7segments_output(tens);
									hundreds = (dist-tens)/100 ;
									GPIO_PORTA_DATA_R |= 0x08; // hundreds 7 - segment enabler
									LED_RED();
								}
								lat1 = lat2;
								long1 = long2;
							}
						}
					}
				}
		}
		else{ 
					for (i=0;i<100;i++){
						y[i]=0;
					}
		}