#include <graphics.h>
#include <math.h>
#define PRECISION 3
#include <iostream>
#include <fstream>
using namespace std;
int posX, posY;
struct Item{
	char productName[ 100 ];
	char productSize[ 30 ]; //regular,large,grand
	double price;
};

Item product[ 21 ];
int table_index = 0;
double total = 0;
int x = 775;
int y = 40;
int test = 0;

void textsize(); 
void Total( int );
char *floatToString ( double num ) {
	int whole_part = num;
	int digit = 0, reminder =0;
	int log_value = log10( num ), index = log_value;
	long wt =0;
	
	// String containg result
	char* str = new char[20];

	if ( num == 0 ) {
		strcpy( str, "0.00" );
		return str;
	}
   	//Initilise stirng to zero
	memset(str, 0 ,20);

   	//Extract the whole part from float num
	for(int  i = 1 ; i < log_value + 2 ; i++) {
		wt  =  pow(10.0,i);
		reminder = whole_part % wt;
		digit = (reminder - digit) / (wt/10);

       //Store digit in string
		str[index--] = digit + 48;              // ASCII value of digit  = digit + 48
		if (index == -1)
		break;    
   	}

    index = log_value + 1;
    str[index] = '.';

	double fraction_part  = num - whole_part;
	double tmp1 = fraction_part,  tmp =0;

   	//Extract the fraction part from  num
   	for( int i= 1; i < PRECISION; i++)
   	{
		wt =10; 
    	tmp  = tmp1 * wt;
		digit = tmp;

      	//Store digit in string
      	str[++index] = digit + 48;           // ASCII value of digit  = digit + 48
      	tmp1 = tmp - digit;
   	}    

   	return str;
}
char *int_to_str( int number ) {
	char *buffer = new char[20];
	itoa ( number, buffer, 10 );
	return buffer;
	delete buffer;
}

void firstpage () {
	
	initwindow ( 1050, 700, "POS", 30, 5 );
	//setcurrentwindow(screen);
	setactivepage(1);
	setvisualpage(1);
	//1
//	readimagefile ( "cat.jpg", 0, 0, 1200, 700 );
	//2
	readimagefile ( "cup.jpg", 1, 25, 1360, 630 );
	//3
	setfillstyle ( SOLID_FILL, COLOR ( 179, 169, 134 ) );
	bar ( 10, 35, 1000, 120 );
	//4
	setfillstyle ( SOLID_FILL, COLOR ( 179, 169, 134 ) );
	bar ( 10, 128, 1000, 530 );
}

void button_page1 () {
	//9 bar of Here
	setcolor ( COLOR ( 49, 49, 49 ) );
	rectangle ( 22, 47, 150, 106 );
	rectangle ( 22, 47, 151, 107 );
	setfillstyle ( SOLID_FILL, COLOR ( 177, 177, 177 ) );
	bar ( 22, 47, 150, 106 );
	// bar of number table 1
	rectangle ( 22, 140, 131, 231 );
	rectangle ( 22, 140, 130, 230 );
	bar ( 22, 140, 130, 230 );
	// bar of number table 2
	rectangle ( 140, 140, 249, 231 );
	rectangle ( 140, 140, 248, 230 );
	bar ( 140, 140, 248, 230 );
	
}

void text_page1 () {
	
	// text of here
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	setcolor ( BLACK );
	settextstyle ( BOLD_FONT, HORIZ_DIR, 1 );
	outtextxy ( 65, 65, "Here" ) ;
	
	//text number 1
	settextstyle ( 10, HORIZ_DIR, 3 );
	setcolor ( BLACK );
	outtextxy ( 70, 173, "1" );
	
	//text number 2
	settextstyle ( 10, HORIZ_DIR, 3 );
	setcolor ( BLACK );
	outtextxy ( 190, 173, "2" );
}
void page2 () {
	//1
	setfillstyle ( SOLID_FILL , COLOR ( 122, 17, 5 ) );
	readimagefile ( "cat.jpg", 1, 1, 1360, 700 );
	//2
	setfillstyle ( SOLID_FILL, 8 );
	readimagefile ( "cup.jpg", 1, 25, 1360, 630 );
	
	//3 bar of menu drink
	setfillstyle ( SOLID_FILL, COLOR ( 179, 169, 134 ) );
	bar ( 80, 35, 680, 150 );
	
	//4 bar of drink91, 91, 91 ) );
	bar ( 10, 160, 760, 520 );
	
	// bar of sub total
	setfillstyle ( SOLID_FILL, COLOR ( 192, 192, 192 ) );
	bar ( 770, 35, 1040, 487 );
	
	// Sub total
	setfillstyle ( SOLID_FILL, COLOR ( 192, 192, 192 ) );
	bar ( 770, 492, 1040, 520 );
	
	//For delete
//	setfillstyle ( SOLID_FILL, RED );
//	bar ( 790, 40, 1020, 150 );
	
}

void button_page_2 () {
	int x = 17, x2 = 125;
	int y = 165, y2 = 255;
	//bar of cold drink
	setcolor ( COLOR ( 49, 49, 49 ) );
	rectangle ( 90, 46, 206, 141 );
	rectangle ( 90, 46, 205, 140 );
	setfillstyle ( SOLID_FILL, COLOR ( 177, 177, 177 ) );
	bar ( 90, 45, 205, 140 );
	
	//bar of Hot Drinks
	rectangle ( 215, 45, 331, 141 );
	rectangle ( 215, 45, 330, 140 );
	bar ( 215, 45, 330, 140 );
	
	//bar of Frappe
	rectangle ( 340, 45, 456, 141 );
	rectangle ( 340, 45, 455, 140 );
	bar ( 340, 45, 455, 140 );
	
	//bar of Smoothies
//	rectangle ( 465, 45, 581, 141 );
//	rectangle ( 465, 45, 580, 140 );
//	bar ( 465, 45, 580, 140 );
	
	// bar of drink
	for ( int i = 0; i < 6; i++ ) {
		if ( i < 6 ) {
			rectangle ( x, y, x2, y2 );
			rectangle ( x, y, x2 + 1, y2 + 1 );
			bar ( x, y, x2, y2 );
			x += 118;
			x2 += 118;
		} else {
			y = 265;
			y2 = 355;
			x -= 118;
			x2 -=118;
			bar ( x, y, x2, y2 );
		}
	}
	
	// Tender & text
	setfillstyle ( SOLID_FILL, COLOR ( 177, 177, 177 ) );
	setcolor ( COLOR ( 49, 49, 49 ) );
	rectangle ( 651, 530, 759, 621 );
	rectangle ( 650, 530, 758, 620 );
	bar ( 650, 530, 758, 620 );
	
	// bar back
//	setcolor ( BLACK );
//	rectangle ( 900, 637, 1030, 694 );
//	rectangle ( 900, 637, 1030, 693 );
//	bar ( 900, 637, 1030, 693 );
	
}

void text_page_2 () {
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 145, 70, "1" );
	outtextxy ( 110, 90, "Cold drink" );
	
	outtextxy ( 270, 70, "2" );
	outtextxy ( 240, 90, "Hot drink" );
	
	outtextxy ( 395, 70, "3" );
	outtextxy ( 375, 90, "Frappe" );
	
//	outtextxy ( 520, 70, "4" );
//	outtextxy ( 485, 90, "Smoothies" );
	
	outtextxy ( 65, 190, "1" );
	outtextxy ( 30, 210, "Iced Mocha");
	
	outtextxy ( 185, 190, "2" );
	outtextxy ( 155, 210, "Iced latte" );
	
	outtextxy ( 305, 180, "3" );
	outtextxy ( 294, 200, "Iced" );
	outtextxy ( 270, 220, "Americano" );
	
	outtextxy ( 423, 180, "4" );
	outtextxy ( 412, 200, "Iced" );
	outtextxy ( 385, 220, "Cappuccino" );
	
	outtextxy ( 541, 180, "5" );
	outtextxy ( 530, 200, "Iced" );
	outtextxy ( 503, 220, "Chocolate" );
	
	outtextxy ( 659, 180, "6" );
	outtextxy ( 648, 200, "Iced" );
	outtextxy ( 615, 220, "Vanilla Latte" );
	
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	outtextxy ( 675, 565, "Tender" );
	
	// text of back
//	settextstyle ( 10, HORIZ_DIR, 3 );
//	outtextxy ( 940, 655, "Back" ); 
	
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	setcolor ( BLUE );
	outtextxy ( 775, 497, "Sub Total($)" );
	
	// Price
	settextstyle( 8, HORIZ_DIR, 1 );
	setcolor( RED );
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	outtextxy ( 990 , 497, floatToString( 0 ) );
	
}
void Output_Total ( int tableIndex, int x, int y ) {
	outtextxy ( x + 38, y, product[ tableIndex ].productName );
	outtextxy ( x + 173, y, product[ tableIndex ].productSize );
}
void Total ( int tableIndex ) {
	settextstyle( COMPLEX_FONT, HORIZ_DIR, 1 );
	setcolor( RED );
	setbkcolor ( COLOR ( 192, 192, 192 ) );
//	total += product[ table_index ].price;
	for ( int i = tableIndex; i <= tableIndex; i++ ) {
		if ( tableIndex == 0 ) {
			Output_Total ( tableIndex, x, y );
			outtextxy ( x + 8, y, int_to_str ( i + 1 ) );
			outtextxy ( x + 213, y, floatToString ( product[ tableIndex ].price ) );
			outtextxy ( x + 20, y, "." );
		} else if ( tableIndex < 9 ) {
			Output_Total ( tableIndex, 775, ( y + ( i * 20 ) ) );
			outtextxy ( x + 213, ( y + ( i * 20 ) ), floatToString ( product[ tableIndex ].price ) );
			outtextxy ( x + 8, ( y + ( i * 20 ) ), int_to_str ( i + 1 ) );
			outtextxy ( x + 20, ( y + ( i * 20 ) ), "." );
		} else {
			Output_Total ( tableIndex, 780, ( y + ( i * 20 ) ) );
			outtextxy ( x + 212, ( y + ( i * 20 ) ), floatToString ( product[ tableIndex ].price ) );
			outtextxy ( x + 8, ( y + ( i * 20 ) ), int_to_str ( i + 1 ) );
			outtextxy ( x + 30, ( y + ( i * 20 ) ), "." );
		}
	}
	//display Total
	if ( total < 10 ) {
		outtextxy ( 990 , 497, floatToString( total ) );
	} else {
		outtextxy ( 980 , 497, floatToString( total ) );
	}
}
void Total_tender () {
	settextstyle( 8, HORIZ_DIR, 1 );
	setbkcolor ( WHITE );
	setcolor ( BLACK );
	outtextxy ( 360, 175, floatToString( 0 ) );
	settextstyle( 8, HORIZ_DIR, 1 );
	setcolor( WHITE );
	setbkcolor ( COLOR ( 43, 43, 43 ) );
	outtextxy ( 320, 235, floatToString ( total ) );
}
void tender ();
void displayChange ( double change ) {
	int y = 40;
	settextstyle( 8, HORIZ_DIR, 1 );
	setcolor( WHITE );
	setbkcolor ( COLOR ( 43, 43, 43 ) );
	if( change > 0 ) outtextxy ( 315, 262, floatToString ( change ) );
	else {
		outtextxy ( 315, 262, floatToString ( change ) );
		outtextxy( 360, 262, "     " );
	}
}
void text_size_drink ();
void beveragesize ( int table_Index, int number ) {
//	int x = 260, x2 = 371, y = 270, y2 = 361;
	//save old screen
	void *buff = new char[ imagesize( 1, 1, 780, 400 ) ];
	getimage( 1, 1, 780, 400, buff );
	
	//bar of them
	setfillstyle ( SOLID_FILL, COLOR ( 102, 105, 130 ) );
	bar ( 250, 200, 780, 400 );
	
	// Text 
	setbkcolor ( COLOR ( 102, 105, 130 ) );
	setcolor ( WHITE );
	outtextxy ( 260, 210, "Beverage size" );
	
	// bar of regular
	setfillstyle ( SOLID_FILL, COLOR ( 177, 177, 177 ) );
	setcolor ( COLOR ( 49, 49, 49 ) );
	rectangle ( 260, 270, 372, 362 );
	rectangle ( 260, 270, 371, 361 );
	bar ( 260, 270, 371, 361 );
	
	// bar of large
	rectangle ( 380, 270, 492, 362 );
	rectangle ( 380, 270, 491, 361 );
	bar ( 380, 270, 491, 361 );
	
	//bar of grand
	rectangle ( 500, 270, 612, 362 );
	rectangle ( 500, 270, 611, 361 );
	bar ( 500, 270, 611, 361 );
	
	//Cancel 
	setfillstyle ( SOLID_FILL, COLOR ( 204, 0, 0 ) );
	rectangle ( 659, 270, 770, 362 );
	rectangle ( 659, 270, 770, 361 );
	bar ( 659, 270, 770, 361 );
	
	text_size_drink ();
	
	//loop wait for mouse click on 1 size
	while( true ) {
		posX=mousex();
		posY=mousey();
		if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
			setcolor ( WHITE );
			rectangle ( 260, 270, 371, 361 );
		} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
			setcolor ( WHITE );
			rectangle ( 380, 270, 491, 361 );
		} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
			setcolor ( WHITE );
			rectangle ( 500, 270, 611, 361 );
		} else if ( posX >= 659 && posX <= 771 && posY >= 270 && posY <= 361 ) {
			setcolor ( WHITE );
			rectangle ( 659, 270, 771, 361 );
		} else {
			setcolor ( COLOR ( 47, 94, 94 ) );
			rectangle ( 260, 270, 371, 361 );
			rectangle ( 380, 270, 491, 361 );
			rectangle ( 500, 270, 611, 361 );
			rectangle ( 659, 270, 771, 361 );
		}
		if ( ismouseclick( WM_LBUTTONDOWN ) ) {
			getmouseclick( WM_LBUTTONDOWN, posX, posY );
			if ( table_index < 20 ) {
				if ( number == 1 ) { // iced mocha
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.75;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.75;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 4.25;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} 
				} else if ( number == 2 ) { // iced latte
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.65;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.65;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 4;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
				} else if ( number == 3 ) { // iced Americano
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.40;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.35;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 3.75;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
				} else if ( number == 4 ) { // iced cappuccino
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.70;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.65;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 4;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
				} else if ( number == 5 ) { // iced chocolate
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.75;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.65;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 4;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}
				} else if ( number == 6 ) { // iced vanilla
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.85;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.65;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 4;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
				} else if ( number == 7 ) { // Americano
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.20;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.00;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 3.65;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}
				} else if ( number == 8 ) { // Caffe Latte
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.40;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.35;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 3.85;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
					total += product[ table_index ].price;
				} else if ( number == 9 ) { // Caffe Mocha
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.75;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.50;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 3.95;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
				} else if ( number == 10 ) { // Cappuccino
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.40;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.85;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 4;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
				} else if ( number == 11 ) { // Espresso
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 1.85;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						break;
					}	
				} else if ( number == 12 ) { // Hot Chocolate
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.50;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.35;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 3.85;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}	
				} else if ( number == 13 || number == 14 || number == 15 || number == 16 || number == 17 || number == 18 ) { // Brown Delight && Mocha Frappe
					if ( posX >= 260 && posX <= 371 && posY >= 270 && posY <= 361 ) {
						//regular
						strcpy ( product[ table_index ].productSize, "R" );
						product[ table_index ].price = 2.95;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 380 && posX <= 491 && posY >= 270 && posY <= 361 ) {
						//large
						strcpy ( product[ table_index ].productSize, "L" );
						product[ table_index ].price = 3.95;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					} else if ( posX >= 500 && posX <= 611 && posY >= 270 && posY <= 361 ) {
						//grand
						strcpy ( product[ table_index ].productSize, "G" );
						product[ table_index ].price = 4.25;
						total += product[ table_index ].price;
						Total( table_index++ );
						break;
					}
				}
				if ( posX >= 659 && posX <= 771 && posY >= 270 && posY <= 361 ) { // cancel
					break;
				}
			} else {
				break;
			}
		}
	}
	//restore the screen
	putimage( 1, 1, buff, COPY_PUT );
}
void text_size_drink () {
	//regular text
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	setcolor ( BLACK );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 290, 305, "Regular" );
	
	//large text
	outtextxy ( 415, 305, "Large" );
	
	//grand text
	outtextxy ( 535, 305, "Grand" );
	
	// text cancel
	setcolor ( WHITE );
	setbkcolor ( COLOR ( 204, 0, 0 ) );
	outtextxy ( 694, 305, "Cancel" );
}

void tender_button () {
	posX = mousex ();
	posY = mousey ();
	// cancel button
	if ( posX >= 255 && posX <= 328 && posY >= 387 && posY <= 448 ) {
		setcolor ( WHITE );
		rectangle ( 254, 386, 329, 449 );
	// clear button
	} else if ( posX >= 338 && posX <= 411 && posY >= 385 && posY <= 451 ) {
		setcolor ( WHITE );
		rectangle ( 338, 385, 411, 451 );
	// OK button
	} else if ( posX >= 420 && posX <= 494 && posY >= 386 && posY <= 450 ) {
		setcolor ( WHITE );
		rectangle ( 420, 386, 494, 450 );
	// 0 Button
	} else if ( posX >= 671 && posX <= 747 && posY >= 386 && posY <= 450 ) {
		setcolor ( WHITE );
		rectangle ( 671, 387, 746, 450 );
	// 3 button
	} else if ( posX >= 672 && posX <= 747 && posY >= 309 && posY <= 373 ) {
		setcolor ( WHITE );
		rectangle ( 672, 309, 747, 373 );
	// 2 button
	} else if ( posX >= 589 && posX <= 663 && posY >= 309 && posY <= 373 ) {
		setcolor ( WHITE );
		rectangle ( 589, 309, 663, 373 );
	// 1 button
	} else if ( posX >= 506 && posX <= 579 && posY >= 309 && posY <= 373 ) {
		setcolor ( WHITE );
		rectangle ( 506, 309, 579, 373 );
	// 4 button
	} else if ( posX >= 506 && posX <= 579 && posY >= 232 && posY <= 295 ) {
		setcolor ( WHITE );
		rectangle ( 506, 232, 579, 295 );
	// 5 button
	} else if ( posX >= 589 && posX <= 663 && posY >= 232 && posY <= 295 ) {
		setcolor ( WHITE );
		rectangle ( 589, 232, 663, 295 );
	// 6 button
	} else if ( posX >= 672 && posX <= 747 && posY >= 232 && posY <= 295 ) {
		setcolor ( WHITE );
		rectangle ( 672, 232, 747, 295 );
	// 9 button
	} else if ( posX >= 672 && posX <= 747 && posY >= 155 && posY <= 218 ) {
		setcolor ( WHITE );
		rectangle ( 672, 155, 747, 218 );
	// 8 button
	} else if ( posX >= 589 && posX <= 663 && posY >= 155 && posY <= 218 ) {
		setcolor ( WHITE );
		rectangle ( 589, 155, 663, 218 );
	// 7 button
	} else if ( posX >= 506 && posX <= 579 && posY >= 155 && posY <= 218 ) {
		setcolor ( WHITE );
		rectangle ( 506, 155, 579, 218 );
	} else {
		setcolor ( COLOR ( 42, 42, 42 ) );
		rectangle ( 254, 386, 329, 449 ); // cancel
		rectangle ( 338, 385, 411, 451 ); // clear
		rectangle ( 420, 386, 494, 450 ); // OK
		rectangle ( 671, 387, 746, 450 ); // 0
		rectangle ( 672, 309, 747, 373 ); // 3
		rectangle ( 589, 309, 663, 373 ); // 2
		rectangle ( 506, 309, 579, 373 ); // 1
		rectangle ( 506, 232, 579, 295 ); // 4
		rectangle ( 589, 232, 663, 295 ); // 5
		rectangle ( 672, 232, 747, 295 ); // 6
		rectangle ( 672, 155, 747, 218 ); // 9
		rectangle ( 589, 155, 663, 218 ); // 8
		rectangle ( 506, 155, 579, 218 ); // 7
	}
}
void DisplayTotal ( int number ) {
	setfillstyle ( SOLID_FILL, COLOR ( 192, 192, 192 ) );
	bar ( 770, 35, 1040, 487 );
	bar ( 770, 492, 1040, 520 );
	settextstyle( 8, HORIZ_DIR, 1 );
	setcolor( RED );
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	total *= number; 
	outtextxy ( 990 , 497, floatToString( total ) );
	
	settextstyle( 10, HORIZ_DIR, 1 );
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	setcolor ( BLUE );
	outtextxy ( 775, 497, "Sub Total($)" );
}
void tender () {
	void *buff = new char[ imagesize( 1, 1, 750, 475 ) ];
	getimage ( 1, 1, 750, 475, buff );
	readimagefile ( "tender.jpg",250 , 100, 750, 475 );
	int page = 5;
	setvisualpage ( page );
	setactivepage ( page );
	int count = 0;
	Total_tender ();
	double pay = 0, change=0;
	displayChange ( change );
//	outtextxy ( 315, 262, floatToString ( change ) );
	while ( 1 ) {
		tender_button();
		if ( ismouseclick ( WM_LBUTTONUP ) ) {
			getmouseclick ( WM_LBUTTONUP, posX, posY );
			if ( count != 3 ) {
				// click on 1
				if ( posX >= 506 && posX <= 579 && posY >= 309 && posY <= 373 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 1;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 2
				} else if ( posX >= 589 && posX <= 663 && posY >= 309 && posY <= 373 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 2;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 3
				} else if ( posX >= 672 && posX <= 747 && posY >= 309 && posY <= 373 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 3;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 4
				} else if ( posX >= 506 && posX <= 579 && posY >= 232 && posY <= 295 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 4;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 5
				} else if ( posX >= 589 && posX <= 663 && posY >= 232 && posY <= 295 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 5;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 6
				} else if ( posX >= 672 && posX <= 747 && posY >= 232 && posY <= 295 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 6;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 7
				} else if ( posX >= 506 && posX <= 579 && posY >= 155 && posY <= 218 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 7;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 8
				} else if ( posX >= 589 && posX <= 663 && posY >= 155 && posY <= 218 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 8;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				// click on 9
				} else if ( posX >= 672 && posX <= 747 && posY >= 155 && posY <= 218 ) {
					setbkcolor ( WHITE );
					setcolor ( BLACK );
					pay *= 10;
					pay += 9;
					outtextxy ( 360, 175, floatToString( pay ) );
					change = pay - total;
					count++;
					if ( change < 0 ) continue;
					displayChange( change );
				} 
				// 0 button
				if ( count > 0 ) {
					if ( posX >= 671 && posX <= 747 && posY >= 386 && posY <= 450 ) {
						setbkcolor ( WHITE );
						setcolor ( BLACK );
						pay *= 10;
						pay += 0;
						outtextxy ( 360, 175, floatToString( pay ) );
						change = pay - total;
						count++;
						if ( change < 0 ) continue;
						displayChange( change );
					}
				}
			}
			// click on clear
			if ( posX >= 338 && posX <= 411 && posY >= 385 && posY <= 451 ) {
				setbkcolor ( WHITE );
				setcolor ( BLACK );
				pay *= 0;
				change *= 0;
				outtextxy ( 360, 175, floatToString ( pay ) );
				outtextxy ( 405, 175, "    " );
				displayChange ( pay );
				count = 0;
			// click on ok
			} else if ( posX >= 420 && posX <= 494 && posY >= 386 && posY <= 450 ) {
				// bar of sub total
				if ( total == 0 && change > 0 ) continue;
				if ( pay == 0 ) continue;
				if ( change < 0 ) continue;
				else {
					ofstream fout;
					fout.open( "DailySale.txt", ios::out | ios::app );
					for ( int i = 0; i < table_index; i++ ) {
						fout << i + 1 << ".  "
							 << product[ i ].productName << "  "
							 << product[ i ].productSize << "  "
							 << product[ i ].price << "$" << endl;
					}
					fout << "\nTotalSale: "<< total << " $\n";
					fout.close();
					total *= 0;
					change *= 0;
					DisplayTotal ( 1 );
					table_index = 0;
					test = 1;
					break;
				}
			// click on cancel
			} else if ( posX >= 255 && posX <= 328 && posY >= 387 && posY <= 448 ) {
				break;
			}
		}
	} 
	putimage( 1, 1, buff, COPY_PUT );
}
void HotDrinkText () {
	//text of Cold drink
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 145, 70, "1" );
	outtextxy ( 110, 90, "Cold drink" ); 
	
	outtextxy ( 270, 70, "2" );
	outtextxy ( 240, 90, "Hot drink" );
	
	outtextxy ( 395, 70, "3" );
	outtextxy ( 375, 90, "Frappe" );
	
//	outtextxy ( 520, 70, "4" );
//	outtextxy ( 485, 90, "Smoothies" );
	
	outtextxy ( 65, 190, "1" );
	outtextxy ( 33, 210, "Americano");
	
	outtextxy ( 185, 190, "2" );
	outtextxy ( 152, 210, "Caffe Latte" );
	
	outtextxy ( 305, 190, "3" );
	outtextxy ( 263, 210, "Caffe Mocha" );
	
	outtextxy ( 421, 190, "4" );
	outtextxy ( 385, 210, "Cappuccino" );
	
	outtextxy ( 545, 190, "5" );
	outtextxy ( 515, 210, "Espresso" );
	
	outtextxy ( 659, 180, "6" );
	outtextxy ( 648, 200, "Hot" );
	outtextxy ( 625, 220, "Chocolate" );
	
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	outtextxy ( 675, 565, "Tender" );
	
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	setcolor ( BLUE );
	outtextxy ( 775, 497, "Sub Total($)" );
	
	// Price
	settextstyle( 8, HORIZ_DIR, 1 );
	setcolor( RED );
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	outtextxy ( 990 , 497, floatToString( 0 ) );
}
void HotDrink () {
	page2();
	button_page_2 ();
	HotDrinkText ();
}

void FrappeText () {
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 145, 70, "1" );
	outtextxy ( 110, 90, "Cold drink" );
	
	outtextxy ( 270, 70, "2" );
	outtextxy ( 240, 90, "Hot drink" );
	
	outtextxy ( 395, 70, "3" );
	outtextxy ( 375, 90, "Frappe" );
	
//	outtextxy ( 520, 70, "4" );
//	outtextxy ( 485, 90, "Smoothies" );
	
	outtextxy ( 65, 190, "1" );
	outtextxy ( 21, 210, "Brown Delight");
	
	outtextxy ( 185, 190, "2" );
	outtextxy ( 138, 210, "Mocha Frappe" );
	
	outtextxy ( 305, 180, "3" );
	outtextxy ( 265, 200, "Mocha Chip" );
	outtextxy ( 280, 220, "Cream" );
	
	outtextxy ( 423, 180, "4" );
	outtextxy ( 395, 200, "Caramel" );
	outtextxy ( 400, 220, "Frappe" );
	
	outtextxy ( 541, 180, "5" );
	outtextxy ( 520, 200, "Vanilla" );
	outtextxy ( 520, 220, "Frappe" );
	
	outtextxy ( 659, 180, "6" );
	outtextxy ( 625, 200, "Chocolate" );
	outtextxy ( 635, 220, "Frappe" );
	
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	outtextxy ( 675, 565, "Tender" );
	
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	setcolor ( BLUE );
	outtextxy ( 775, 497, "Sub Total($)" );
	
	// Price
	settextstyle( 8, HORIZ_DIR, 1 );
	setcolor( RED );
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	outtextxy ( 990 , 497, floatToString( 0 ) );
}

void Frappe () {
	page2 ();
	button_page_2 ();
	FrappeText ();
}

void SmoothieText () {
	//text of Cold drink
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 145, 70, "1" );
	outtextxy ( 110, 90, "Cold drink" );
	
	//text of Hot Drink
	outtextxy ( 270, 70, "2" );
	outtextxy ( 240, 90, "Hot drink" );
	
	//Text of Frappe
	outtextxy ( 395, 70, "3" );
	outtextxy ( 375, 90, "Frappe" );
	
	//Text of Smoothies
	outtextxy ( 520, 70, "4" );
	outtextxy ( 485, 90, "Smoothies" );
	
	//Iced Blueberry
	outtextxy ( 65, 180, "1" );
	outtextxy ( 21, 200, "Blueberry");
	outtextxy ( 21, 220, "Smoothies");
	
	//Iced cafe latte
	outtextxy ( 185, 190, "2" );
	outtextxy ( 138, 210, "Mocha Frappe" );
	
	//Iced Americano
	outtextxy ( 305, 180, "3" );
	outtextxy ( 265, 200, "Mocha Chip" );
	outtextxy ( 280, 220, "Cream" );
	
	//Tender
	setbkcolor ( COLOR ( 177, 177, 177 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	outtextxy ( 675, 565, "Tender" );
	
	// Text Sub total
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	settextstyle ( 10, HORIZ_DIR, 1 );
	setcolor ( BLUE );
	outtextxy ( 775, 497, "Sub Total($)" );
	
	// Price
	settextstyle( 8, HORIZ_DIR, 1 );
	setcolor( RED );
	setbkcolor ( COLOR ( 192, 192, 192 ) );
	outtextxy ( 990 , 497, floatToString( 0 ) );
}

void Smoothie () {
	page2 ();
	button_page_2 ();
	SmoothieText ();
}

void clickCold () {
	setcolor ( WHITE );
	rectangle ( 90, 46, 206, 141 );
	rectangle ( 90, 46, 205, 140 );
	setfillstyle( SOLID_FILL, COLOR ( 197, 197, 197 ) );
	bar ( 91, 46, 205, 140 );
	
	setbkcolor ( COLOR ( 197, 197, 197 ) );
	setcolor ( BLACK );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 145, 70, "1" );
	outtextxy ( 110, 90, "Cold drink" );
}

void clickHot () {
	setcolor ( WHITE );
	rectangle ( 215, 45, 331, 141 );
	rectangle ( 215, 45, 330, 140 );
	setfillstyle( SOLID_FILL, COLOR ( 197, 197, 197 ) );
	bar ( 215, 45, 330, 140 );
	
	setbkcolor ( COLOR ( 197, 197, 197 ) );
	setcolor ( BLACK );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 270, 70, "2" );
	outtextxy ( 240, 90, "Hot drink" );
}

void clickFrappe () {
	setcolor ( WHITE );
	rectangle ( 340, 45, 456, 141 );
	rectangle ( 340, 45, 455, 140 );
	setfillstyle( SOLID_FILL, COLOR ( 197, 197, 197 ) );
	bar ( 340, 45, 455, 140 );
	
	setbkcolor ( COLOR ( 197, 197, 197 ) );
	setcolor ( BLACK );
	settextstyle ( 3, HORIZ_DIR, 1 );
	outtextxy ( 395, 70, "3" );
	outtextxy ( 375, 90, "Frappe" );
}

main () {
	initwindow ( 1050, 630, "POS", 30, 5 );
	int page=1;
	ofstream fout;
	fout.open( "DailySale.txt", ios::out );
	fout << " ";

	setactivepage( 1 );
	page2 ();
	button_page_2 ();
	text_page_2 ();
	
	setactivepage ( 2 );
	HotDrink ();
	
	setactivepage ( 3 );
	Frappe ();
	
	setactivepage( 1 );
	setvisualpage( 1 ); 
	clickCold ();
	
	while ( true ) {
		
		posX = mousex ();
		posY = mousey ();
		if ( posX >= 17 && posX <= 125 && posY >= 165 && posY <= 255 ) { // iced mocha
			setcolor ( WHITE );
			rectangle ( 15, 163, 127, 256 );
		} else if ( posX >= 650 && posX <= 758 && posY >= 530 && posY <= 620 ) { // tender
			setcolor ( WHITE );
			rectangle ( 649, 529, 759, 620 );
		} else if ( posX >= 136 && posX <= 242 && posY >= 166 && posY <= 255 ) { // iced latte
			setcolor( WHITE );
			rectangle ( 134, 164, 244, 256 );
		} else if ( posX >= 90 && posX <= 206 && posY >= 45 && posY <= 140 ) { // Cold
			setcolor( WHITE );
			rectangle ( 90, 43, 207, 142 );
		} else if ( posX >= 215 && posX <= 330 && posY >= 45 && posY <= 140 ) { // Hot
			setcolor( WHITE );
			rectangle ( 213, 43, 332, 142 );
		} else if ( posX >= 340 && posX <= 456 && posY >= 45 && posY <= 140 ) { // frappe
			setcolor( WHITE );
			rectangle ( 338, 43, 457, 142 );
		} else if ( posX >= 254 && posX <= 361 && posY >= 166 && posY <= 255 ) { //Iced Americano
			setcolor( WHITE );
			rectangle ( 250, 165, 362, 256 );
		} else if ( posX >= 374 && posX <= 480 && posY >= 166 && posY <= 255 ) { //Iced Cappuccino
			setcolor( WHITE );
			rectangle ( 370, 165, 479, 256 );
		} else if ( posX >= 493 && posX <= 598 && posY >= 166 && posY <= 255 ) { //Iced Chocolate
			setcolor( WHITE );
			rectangle ( 488, 166, 598, 256 );
		} else if ( posX >= 612 && posX <= 717 && posY >= 166 && posY <= 255 ) { //Iced Vanilla
			setcolor( WHITE );
			rectangle ( 608, 166, 716, 256 );
		} else {
			setcolor( COLOR ( 49, 49, 49 ) );
//			rectangle ( 900, 637, 1030, 693 );// back
			rectangle ( 15, 163, 127, 256 );//iced mocha
			rectangle ( 134, 164, 244, 256 );//iced latte
			rectangle ( 250, 165, 362, 256 );//Iced Americano
			rectangle ( 370, 165, 479, 256 );//Iced Cappuccino
			rectangle ( 488, 166, 598, 256 );//Iced Chocolate
			rectangle ( 608, 166, 716, 256 );//Iced Vanilla
			rectangle ( 649, 529, 759, 620 );//tender
			rectangle ( 90, 43, 207, 142 );//Cold
			rectangle ( 213, 43, 332, 142 );//Hot
			rectangle ( 338, 43, 457, 142 );//frappe
		}
		getmouseclick ( WM_LBUTTONDOWN, posX, posY );
		if ( page == 1 ) {
			if ( test == 1 ) {
				setfillstyle ( SOLID_FILL, COLOR ( 192, 192, 192 ) );
				bar ( 770, 35, 1040, 487 );
				outtextxy ( 913, 497, "       " );
				settextstyle( 8, HORIZ_DIR, 1 );
				setcolor( RED );
				setbkcolor ( COLOR ( 192, 192, 192 ) );
				outtextxy ( 990 , 497, floatToString( total ) );
				
				settextstyle( 10, HORIZ_DIR, 1 );
				setbkcolor ( COLOR ( 192, 192, 192 ) );
				setcolor ( BLUE );
				outtextxy ( 775, 497, "Sub Total($)" );
				test = 0;
			}
			for ( int i = 0; i < table_index; i++ ) {
				Total ( i );
			}
			if ( posX >= 215 && posX <= 330 && posY >= 45 && posY <= 140 ) { // Hot
				test = 1;
				page = 2;
				setactivepage ( page );
				setvisualpage ( page );
				clickHot ();
			} else if ( posX >= 340 && posX <= 456 && posY >= 45 && posY <= 140 ) { // frappe
				test = 1;
				page = 3;
				setactivepage ( page );
				setvisualpage ( page );
				clickFrappe ();
			} else if ( posX >= 465 && posX <= 580 && posY >= 45 && posY <= 140 ) { // smoothie
				page = 4;
				setactivepage ( page );
				setvisualpage ( page );
			} else if ( posX >= 17 && posX <= 125 && posY >=165 && posY <= 255 ) { // iced mocha
				strcpy ( product[ table_index ].productName, "Iced mocha" );
				beveragesize ( table_index, 1 );
			} else if ( posX >= 136 && posX <= 242 && posY >= 166 && posY <= 255 ) { // iced latte
				strcpy ( product[ table_index ].productName, "Iced Caffe" );
				beveragesize ( table_index, 2 );
			} else if ( posX >= 254 && posX <= 361 && posY >= 166 && posY <= 255 ) { //Iced Americano
				strcpy ( product[ table_index ].productName, "Iced Americ" );
				beveragesize ( table_index, 3 );
			} else if ( posX >= 374 && posX <= 480 && posY >= 166 && posY <= 255 ) { //Iced Cappuccino
				strcpy ( product[ table_index ].productName, "Iced Cappu" );
				beveragesize ( table_index, 4 );
			} else if ( posX >= 493 && posX <= 598 && posY >= 166 && posY <= 255 ) { //Iced Chocolate
				strcpy ( product[ table_index ].productName, "Iced Choco" );
				beveragesize ( table_index, 5 );
			} else if ( posX >= 612 && posX <= 717 && posY >= 166 && posY <= 255 ) { //Iced Vanilla
				strcpy ( product[ table_index ].productName, "Iced Vanilla" );
				beveragesize ( table_index, 6 );
			} else if ( posX >= 650 && posX <= 758 && posY >= 530 && posY <= 620 ) { // tender
				tender ();
			} else if ( posX >= 90 && posX <= 206 && posY >= 45 && posY <= 140 ) { // Cold
				clickCold ();
			} 
		} else if ( page == 2 ) { // Hot
			if ( test == 1 ) {
				setfillstyle ( SOLID_FILL, COLOR ( 192, 192, 192 ) );
				bar ( 770, 35, 1040, 487 );
				outtextxy ( 913, 497, "       " );
				settextstyle( 8, HORIZ_DIR, 1 );
				setcolor( RED );
				setbkcolor ( COLOR ( 192, 192, 192 ) );
				outtextxy ( 990 , 497, floatToString( total ) );
				
				settextstyle( 10, HORIZ_DIR, 1 );
				setbkcolor ( COLOR ( 192, 192, 192 ) );
				setcolor ( BLUE );
				outtextxy ( 775, 497, "Sub Total($)" );
				test = 0;
			}
			for ( int i = 0; i < table_index; i++ ) {
				Total ( i );
			}
			if ( posX >= 90 && posX <= 206 && posY >= 45 && posY <= 140 ) { // Cold
				test = 1;
				page = 1;
				setactivepage ( page );
				setvisualpage ( page );
				clickCold ();
			} else if ( posX >= 340 && posX <= 456 && posY >= 45 && posY <= 140 ) { // frappe
				test = 1;
				page = 3;
				setactivepage ( page );
				setvisualpage ( page );
				clickFrappe ();
			} else if ( posX >= 465 && posX <= 580 && posY >= 45 && posY <= 140 ) { // smoothie
				page = 4;
				setactivepage ( page );
				setvisualpage ( page );
			} else if ( posX >= 17 && posX <= 125 && posY >=165 && posY <= 255 ) { // iced mocha
				strcpy ( product[ table_index ].productName, "Americano" );
				beveragesize ( table_index, 7 );
			} else if ( posX >= 136 && posX <= 242 && posY >= 166 && posY <= 255 ) { // iced latte
				strcpy ( product[ table_index ].productName, "Cafe Latte" );
				beveragesize ( table_index, 8 );
			} else if ( posX >= 254 && posX <= 361 && posY >= 166 && posY <= 255 ) { //Iced Americano
				strcpy ( product[ table_index ].productName, "Cafe Mocha" );
				beveragesize ( table_index, 9 );
			} else if ( posX >= 374 && posX <= 480 && posY >= 166 && posY <= 255 ) { //Iced Cappuccino
				strcpy ( product[ table_index ].productName, "Cappuccino" );
				beveragesize ( table_index, 10 );
			} else if ( posX >= 493 && posX <= 598 && posY >= 166 && posY <= 255 ) { //Iced Chocolate
				strcpy ( product[ table_index ].productName, "Espresso" );
				beveragesize ( table_index, 11 );
			} else if ( posX >= 612 && posX <= 717 && posY >= 166 && posY <= 255 ) { //Iced Vanilla
				strcpy ( product[ table_index ].productName, "Hot Choco" );
				beveragesize ( table_index, 12 );
			} else if ( posX >= 650 && posX <= 758 && posY >= 530 && posY <= 620 ) { // tender
				tender ();
			}
		} else if ( page == 3 ) { // Frappe
			if ( test == 1 ) {
				setfillstyle ( SOLID_FILL, COLOR ( 192, 192, 192 ) );
				bar ( 770, 35, 1040, 487 );
				outtextxy ( 913, 497, "       " );
				settextstyle( 8, HORIZ_DIR, 1 );
				setcolor( RED );
				setbkcolor ( COLOR ( 192, 192, 192 ) );
				outtextxy ( 990 , 497, floatToString( total ) );
				
				settextstyle( 10, HORIZ_DIR, 1 );
				setbkcolor ( COLOR ( 192, 192, 192 ) );
				setcolor ( BLUE );
				outtextxy ( 775, 497, "Sub Total($)" );
				test = 0;
			}
			for ( int i = 0; i < table_index; i++ ) {
				Total ( i );
			}
			if ( posX >= 215 && posX <= 330 && posY >= 45 && posY <= 140 ) { // Hot
				test = 1;
				page = 2;
				setactivepage ( page );
				setvisualpage ( page );
				clickHot ();
			} else if ( posX >= 90 && posX <= 206 && posY >= 45 && posY <= 140 ) { // Cold
				test = 1;
				page = 1;
				setactivepage ( page );
				setvisualpage ( page );
				clickCold ();
			} else if ( posX >= 465 && posX <= 580 && posY >= 45 && posY <= 140 ) { // smoothie
				page = 4;
				setactivepage ( page );
				setvisualpage ( page );
			} else if ( posX >= 17 && posX <= 125 && posY >=165 && posY <= 255 ) { // iced mocha
				strcpy ( product[ table_index ].productName, "Brown Deli" );
				beveragesize ( table_index, 13 );
			} else if ( posX >= 136 && posX <= 242 && posY >= 166 && posY <= 255 ) { // iced latte
				strcpy ( product[ table_index ].productName, "Mocha Frap" );
				beveragesize ( table_index, 14 );
			} else if ( posX >= 254 && posX <= 361 && posY >= 166 && posY <= 255 ) { //Iced Americano
				strcpy ( product[ table_index ].productName, "Mocha Chip" );
				beveragesize ( table_index, 15 );
			} else if ( posX >= 374 && posX <= 480 && posY >= 166 && posY <= 255 ) { //Iced Cappuccino
				strcpy ( product[ table_index ].productName, "Caramel F" );
				beveragesize ( table_index, 16 );
			} else if ( posX >= 493 && posX <= 598 && posY >= 166 && posY <= 255 ) { //Iced Chocolate
				strcpy ( product[ table_index ].productName, "Vanilla F" );
				beveragesize ( table_index, 17 );
			} else if ( posX >= 612 && posX <= 717 && posY >= 166 && posY <= 255 ) { //Iced Vanilla
				strcpy ( product[ table_index ].productName, "Chocolate F" );
				beveragesize ( table_index, 18 );
			} else if ( posX >= 650 && posX <= 758 && posY >= 530 && posY <= 620 ) { // tender
				tender ();
			}
		} else if ( page == 4 ) { // Smoothies
			if ( posX >= 215 && posX <= 330 && posY >= 45 && posY <= 140 ) { // Hot
				page = 2;
				setactivepage ( page );
				setvisualpage ( page );
			} else if ( posX >= 90 && posX <= 206 && posY >= 45 && posY <= 140 ) { // Cold
				page = 1;
				setactivepage ( page );
				setvisualpage ( page );
			} else if ( posX >= 340 && posX <= 456 && posY >= 45 && posY <= 140 ) { // frappe
				page = 3;
				setactivepage ( page );
				setvisualpage ( page );
			}
		}
	}
	closegraph ();
}
