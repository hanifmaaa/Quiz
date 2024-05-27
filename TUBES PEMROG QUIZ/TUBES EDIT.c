#include <stdio.h> //library standar input dan output
#include <conio.h> //library untuk menggunakan fungsi getch
#include <stdlib.h> //library standar operasi standar pembanding dan konversi
#include <ctype.h> //library untuk mengelompokkan dan memanipulasi karakter
#include <string.h> //library untuk mengolah tipe data string
#include <windows.h> //library untuk menampilkan warna

void tips(); //untuk mendeklarasikan prosedur tips
void soalkuis(); //untuk mendeklarasikan prosedur soalkuis
void hasiltertinggi(); //untuk mendeklarasikan prosedur hasiltertinggi
void edit_score(float, char[]); //untuk mendeklarasikan prosedur edit_score berparameter float dan char

int main(){ //gerbang utama suatu program
    char pilihan;
    char agama, elektronika, pengetahuanumum;
    int point,r1,i,n,r2,r3,r4;
    float nilai;
    char nama[50];
    system("Color F5");
	tampilanmenu :
	        system("cls");
	    	printf("\t\t>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<");
            printf("\n\t\t>        SELAMAT DATANG         <");
            printf("\n\t\t>              DI               <");
            printf("\n\t\t>       KUIS PENGETAHUAN        <");
            printf("\n\t\t>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<");
            printf("\n\t\t_________________________________");
            printf("\n\n\t\t BERDO'ALAH SEBELUM MENGERJAKAN");
            printf("\n\t\t_________________________________");
            printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");
            printf("\n\t>         Klik S untuk memulai                   <");
            printf("\n\t>         Klik V untuk melihat hasil tertinggi   <");
            printf("\n\t>         Klik H untuk bantuan                   <");
            printf("\n\t>         Klik Q untuk keluar                    <");
            printf("\n\t>         Klik R untuk mereset skor              <");
            printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");

            pilihan = getch();
            if (pilihan == 'v' || pilihan == 'V'){
                hasiltertinggi();
                getch();
                goto tampilanmenu;
            }else if (pilihan == 'h' || pilihan == 'H'){
                system("cls");
                tips();
                getch();
                goto tampilanmenu;
            }else if (pilihan == 'q' || pilihan == 'Q'){
                exit(1);
            }else if (pilihan == 's' || pilihan == 'S'){
                system("cls");
                printf("\n\n\n\n\n\t\tMasukkan Nama Anda : ");
                gets(nama);
                system("cls");
                printf("------------------  Selamat datang %s di KUIS PENGETAHUAN --------------------------", nama);
                printf("\n\nPilih kategori : ");
                printf("\n\nA - Agama Islam");
                printf("\n\nK - Elektronika");
				printf("\n\nD - Pengetahuan Umum");
            	pilihan = getch();
            	if (pilihan == 'a' || pilihan == 'A'){
            		goto agama;
            	}else if (pilihan == 'k' || pilihan == 'K'){
            		goto elektronika;
				}else {
					goto tampilanmenu;
				}
				agama :
					system("cls");
					printf("Pilih Kesulitan\n");
					printf("\n\nO - Mudah");
					printf("\n\nK - Sedang");
					printf("\n\nL - Sulit");
					pilihan = getch ();
					if (pilihan == 'o' || pilihan == 'O'){
						goto mudahAgama;
					}else if (pilihan == 'k' || pilihan == 'K'){
						goto sedangAgama;
					}else if (pilihan == 'l' || pilihan == 'L'){
						goto sulitAgama;
					}else{
						goto tampilanmenu;
					}
				mudahAgama :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalmudahAgama;
                	}else {
                    goto tampilanmenu;
                }
                soalmudahAgama :
                	system("cls");
                	point = 0;
                	for(i=1;i<=5;i++){
                		system("cls");
                		r1=i;
                		switch(r1)
                		{
                		case 1:
                			printf("\n\n1. Rukun Islam ada berapa?");
                			printf("\n\nA.2\t\tB.3\n\nC.8\t\tD.5");
                			pilihan = getch();
                			if(pilihan == 'd' || pilihan == 'D'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 2 :
							printf("\n\n2. Ada berapa sifat wajib Allah?");
                			printf("\n\nA.20\t\tB.18\n\nC.5\t\tD.12");
                			pilihan = getch();
                			if(pilihan == 'a' || pilihan == 'A'){
                				printf("\n\Benar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah A\n\n");
								getch();
								break;
							}
						case 3 :
							printf("\n\n3. Nabi dan Rasul yang terakhir adalah..");
                			printf("\n\nA.Nabi Yunus\t\tB.Nabi Yahya\n\nC.Nabi Muhammad\t\tD.Nabi Isa");
                			pilihan = getch();
                			if(pilihan == 'c' || pilihan == 'C'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						case 4 :
							printf("\n\n4. Ada berapa surat dalam Al-Quran?");
                			printf("\n\nA.118\t\tB.114\n\nC.112\t\tD.120");
                			pilihan = getch();
                			if(pilihan == 'b' || pilihan == 'B'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah B\n\n");
								getch();
								break;
							}
						case 5 :
							printf("\n\n5. Rukun iman yang terakhir adalah iman kepada...");
                			printf("\n\nA.Qada dan Qadar\t\tB.Kitab-Kitab Allah\n\nC.Allah\t\t\t\tD.Nabi dan Rasul");
                			pilihan = getch();
                			if(pilihan == 'a' || pilihan == 'A'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				goto nilai;
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah A\n\n");
								getch();
								break;
							}
						}
					}
				sedangAgama :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalsedangAgama;
                	}else {
                    goto tampilanmenu;
                }
                soalsedangAgama :
                	system("cls");
                	point = 0;
                	for(i=1;i<=5;i++){
                		system("cls");
                		r2=i;
                		switch(r2)
                		{
                		case 1:
                			printf("\n\n1. Apa itu suudzan");
                			printf("\n\nA.Berbuat buruk\t\t\tB.Berkata buruk\n\nC.Berprasangka buruk\t\tD.Berkelakuan buruk");
                			pilihan = getch();
                			if(pilihan == 'c' || pilihan == 'C'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						case 2 :
							printf("\n\n2. Qudrat dalam sifat wajib Allah artinya...");
                			printf("\n\nA.Berkehendak\t\tB.Kekal\n\nC.Esa\t\t\tD.Berkuasa");
                			pilihan = getch();
                			if(pilihan == 'd' || pilihan == 'D'){
                				printf("\n\Benar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 3 :
							printf("\n\n3. Al-Quran diturunkan ke bumi selama...");
                			printf("\n\nA.22 tahun 2 bulan 12 hari\t\tB.22 tahun 2 bulan 20 hari\n\nC.22 tahun 2 bulan 22 hari\t\tD.22 tahun 20 bulan 2 hari");
                			pilihan = getch();
                			if(pilihan == 'c' || pilihan == 'C'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						case 4 :
							printf("\n\n4. Mukjizat yang diberikan kepada Nabi Muhammad salah satunya adalah...");
                			printf("\n\nA.Al-Quran\t\t\tB.Tidak hangus terbakar api\n\nC.Dapat mengendalikan angin\t\tD.Dapat berbicara dengan hewan");
                			pilihan = getch();
                			if(pilihan == 'a' || pilihan == 'A'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah A\n\n");
								getch();
								break;
							}
						case 5 :
							printf("\n\n5. Puasa yang dilaksanakan setiap tanggal 13,14,15 adalah puasa..");
                			printf("\n\nA.Syawal\t\tB.Arafah\n\nC.Ayyamul Bidh\t\t\t\tD.Senin Kamis");
                			pilihan = getch();
                			if(pilihan == 'c' || pilihan == 'C'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				goto nilai;
                				break;
							}else{
								printf("\n\nSalah!!Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						}
					}
				sulitAgama :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalsulitAgama;
                	}else {
                    goto tampilanmenu;
                	}
                soalsulitAgama :
                	system("cls");
                	point = 0;
                	for(i=1;i<=5;i++){
                		system("cls");
                		r3=i;
                		switch(r3)
                		{
                		case 1:
                			printf("\n\n1. Apa yang dimaksud dengan konsep tauhid dalam Islam?");
    						printf("\n\nA. Percaya kepada banyak tuhan\tB. Percaya bahwa Allah adalah satu-satunya Tuhan\nC. Percaya pada reinkarnasi\tD. Percaya pada kekuatan alam");
    						pilihan = getch();
   							if (pilihan == 'b' || pilihan == 'B') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah B\n\n");
        						getch();
        						break;
    						}
						case 2 :
							printf("\n\n2. Jelaskan konsep qadar (takdir) dalam Islam");
    						printf("\n\nA. Keyakinan bahwa semua kejadian adalah hasil usaha manusia\tB. Keyakinan bahwa semua kejadian adalah kebetulan\nC. Keyakinan bahwa semua kejadian telah ditetapkan oleh Allah\tD. Keyakinan bahwa semua kejadian adalah hasil doa");
    						pilihan = getch();
    						if (pilihan == 'c' || pilihan == 'C') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah C\n\n");
    							getch();
								break;
							}
						case 3 :
							printf("\n\n3. Jelaskan arti dan pentingnya puasa Ramadan dalam agama Islam.");
    						printf("\n\nA. Bulan untuk berlibur\tB. Bulan untuk menambah rezeki\nC. Bulan untuk menahan diri dari makan, minum, dan perbuatan buruk dari fajar hingga matahari terbenam\tD. Bulan untuk beribadah tanpa pantangan");
    						pilihan = getch();
    						if (pilihan == 'c' || pilihan == 'C') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						case 4 :
							printf("\n\n4. Bagaimana pandangan Islam tentang pernikahan dan keluarga?");
    						printf("\n\nA. Pernikahan tidak penting\tB. Keluarga bukanlah prioritas\nC. Pernikahan adalah ikatan suci dan keluarga adalah unit dasar masyarakat\tD. Pernikahan hanya untuk menghasilkan keturunan");
    						pilihan = getch();
    						if (pilihan == 'c' || pilihan == 'C') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						case 5 :
							printf("\n\n5. Apa yang dimaksud dengan sunnah dalam Islam, dan bagaimana pengaruhnya dalam kehidupan umat Muslim?");
    						printf("\n\nA. Hukum wajib yang harus diikuti\tB. Tradisi yang ditinggalkan\nC. Tindakan, perkataan, dan persetujuan Nabi Muhammad yang menjadi contoh bagi umat Muslim\tD. Cerita rakyat yang tidak relevan");
    						pilihan = getch();
    						if (pilihan == 'c' || pilihan == 'C') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						}
					}
				elektronika :
					system("cls");
					printf("Pilih Kesulitan\n");
					printf("\n\nO - Mudah");
					printf("\n\nK - Sedang");
					printf("\n\nL - Sulit");
					pilihan = getch ();
					if (pilihan == 'o' || pilihan == 'O'){
						goto mudahElka;
					}else if (pilihan == 'k' || pilihan == 'K'){
						goto sedangElka;
					}else if (pilihan == 'l' || pilihan == 'L'){
						goto sulitElka;
					}else{
						goto tampilanmenu;
					}
				mudahElka :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalmudahElka;
                	}
                	else {
                    goto tampilanmenu;
                }
                soalmudahElka :
                	system("cls");
                	point = 0;
                	for(i=1;i<=5;i++){
                		system("cls");
                		r4=i;
                		switch(r4)
                		{
                		case 1:
                			printf("\n\n1. Warna apa yang mewakili nilai 5 pada kode warna resistor?");
    						printf("\n\nA. Coklat\tB. Hijau\nC. Merah\tD. Kuning");
    						pilihan = getch();
    						if (pilihan == 'b' || pilihan == 'B') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah B\n\n");
								getch();
								break;
							}
						case 2 :
							printf("\n\n2. Berapakah nilai resistor dengan kode warna Merah, Ungu, Merah, Emas?");
    						printf("\n\nA. 2700 ohm\tB. 270 ohm\nC. 27000 ohm\tD. 270000 ohm");
    						pilihan = getch();
    						if (pilihan == 'a' || pilihan == 'A') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah A\n\n");
                				getch();
                				break;
							}
						case 3 :
							printf("\n\n3. Mana yang termasuk ciri-ciri rangkaian seri?");
    						printf("\n\nA. Tegangan berbeda setiap resistor\nB. Arus total sama\nC. Resistor terhubung paralel\nD. Semua benar");
    						pilihan = getch();
    						if (pilihan == 'b' || pilihan == 'B') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah B\n\n");
        						getch;
								break;
							}
						case 4 :
							printf("\n\n4. Mana yang termasuk ciri-ciri rangkaian paralel?");
    						printf("\n\nA. Arus total sama\nB. Resistor terhubung seri\nC. Tegangan sama pada setiap resistor\nD. Tidak ada yang benar");
   							pilihan = getch();
    						if (pilihan == 'c' || pilihan == 'C') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah C\n\n");
								getch();
								break;
							}
						case 5 :
							printf("\n\n5. Berapakah nilai resistor dengan kode warna Coklat, Hitam, Merah, Perak?");
    						printf("\n\nA. 1.0 ohm\tB. 100 ohm\nC. 1000 ohm\tD. 10 ohm");
    						pilihan = getch();
    						if (pilihan == 'b' || pilihan == 'B') {
        						printf("\n\nBenar!!");point++;
        						getch();
        						break;
    						} else {
        						printf("\n\nSalah!! Jawaban benar adalah B\n\n");
								getch();
								break;
							}
						}
					}
				sedangElka :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalsedangElka;
                	}
                	else {
                    goto tampilanmenu;
                }
                soalsedangElka :
                	system("cls");
                	point = 0;
                	for(i=1;i<=5;i++){
                		system("cls");
                		r2=i;
                		switch(r2)
                		{
                		case 1:
                			printf("\n\nRukun Islam ada berapa?");
                			printf("\n\nA.2\t\tB.3\n\nC.8\t\tD.5");
                			pilihan = getch();
                			if(pilihan == 'd' || pilihan == 'D'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 2 :
							printf("\n\nAda berapa sifat wajib Allah?");
                			printf("\n\nA.20\t\tB.18\n\nC.5\t\tD.12");
                			pilihan = getch();
                			if(pilihan == 'a' || pilihan == 'A'){
                				printf("\n\Benar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 3 :
							printf("\n\nNabi dan Rasul yang terakhir adalah..");
                			printf("\n\nA.Nabi Yunus\t\tB.Nabi Yahya\n\nC.Nabi Muhammad\t\tD.Nabi Isa");
                			pilihan = getch();
                			if(pilihan == 'c' || pilihan == 'C'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 4 :
							printf("\n\nAda berapa surat dalam Al-Quran?");
                			printf("\n\nA.118\t\tB.114\n\nC.112\t\tD.120");
                			pilihan = getch();
                			if(pilihan == 'b' || pilihan == 'B'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 5 :
							printf("\n\nRukun iman yang terakhir adalah iman kepada...");
                			printf("\n\nA.Qada dan Qadar\t\tB.Kitab-Kitab Allah\n\nC.Allah\t\t\t\tD.Nabi dan Rasul");
                			pilihan = getch();
                			if(pilihan == 'a' || pilihan == 'A'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				goto nilai;
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						}
					}
				sulitElka :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalsulitElka;
                	}
                	else {
                    goto tampilanmenu;
                }
                soalsulitElka :
                	system("cls");
                	point = 0;
                	for(i=1;i<=5;i++){
                		system("cls");
                		r3=i;
                		switch(r3)
                		{
                		case 1:
                			printf("\n\nRukun Islam ada berapa?");
                			printf("\n\nA.2\t\tB.3\n\nC.8\t\tD.5");
                			pilihan = getch();
                			if(pilihan == 'd' || pilihan == 'D'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 2 :
							printf("\n\nAda berapa sifat wajib Allah?");
                			printf("\n\nA.20\t\tB.18\n\nC.5\t\tD.12");
                			pilihan = getch();
                			if(pilihan == 'a' || pilihan == 'A'){
                				printf("\n\Benar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 3 :
							printf("\n\nNabi dan Rasul yang terakhir adalah..");
                			printf("\n\nA.Nabi Yunus\t\tB.Nabi Yahya\n\nC.Nabi Muhammad\t\tD.Nabi Isa");
                			pilihan = getch();
                			if(pilihan == 'c' || pilihan == 'C'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 4 :
							printf("\n\nAda berapa surat dalam Al-Quran?");
                			printf("\n\nA.118\t\tB.114\n\nC.112\t\tD.120");
                			pilihan = getch();
                			if(pilihan == 'b' || pilihan == 'B'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						case 5 :
							printf("\n\nRukun iman yang terakhir adalah iman kepada...");
                			printf("\n\nA.Qada dan Qadar\t\tB.Kitab-Kitab Allah\n\nC.Allah\t\t\t\tD.Nabi dan Rasul");
                			pilihan = getch();
                			if(pilihan == 'a' || pilihan == 'A'){
                				printf("\n\nBenar!!");point++;
                				getch();
                				goto nilai;
                				break;
							}
							else{
								printf("\n\nSalah!!Jawaban benar adalah D\n\n");
								getch();
								break;
							}
						}
					}
                    nilai :
                        system("cls");
                        nilai=(float)point*200000;
                        if (nilai >= 2000000 )
                        {
                            printf("\n\n\t\t\t**************** SELAMAT *****************");
                            printf("\n\n\t\t\tKAMU MENDAPATKAN HADIAH TERTINGGI!!!!!!!!!");
                            printf("\n\t\t\tKamu mendapatkan %.2f", nilai);
                            printf("\n\t\t\tTerimakasih!!");
                            goto terus;
                        }

                        else if (nilai > 0 && nilai < 2000000)
                            {
                            printf("\n\n\t\t\t**************** SELAMAT *****************");
                            printf("\n\t\t\tKamu mendapatkan %.2f", nilai);
                            goto terus;
                        }

                        else
                        {
                            printf("\n\n\t\t\t******** MAAF KAMU  TIDAK MENDAPATKAN HADIAH APAPUN ********");
                            printf("\n\t\t\tTerimakasih atas partisipasinya");
                            printf("\n\t\t\tCobalah kembali");
                            goto terus;
                        }

                        terus :
                            printf("\n\nKlik Y untuk memulai kembali");
                            printf("\nKlik apapun untuk kembali ke menu");
                            pilihan = getch();
                            if (pilihan == 'y' || pilihan == 'Y')
                            {
                                goto mudahAgama;
                            }
                            else
                            {
                                edit_score(nilai, nama);
                                goto tampilanmenu;
                            }

        }
}

void tips(){
    printf("\n\nbantuan :  ");
    printf("\n-------------------------------------------------------------------------");
    printf("\n>> Terdapat 2 sesi, yaitu sesi PEMANASAN dan sesi CARI POIN");
    printf("\n>> Di sesi PEMANASAAN, terdapat 4 soal yang harus di jawab");
    printf("\n>> Diperlukan 3 jawaban benar untuk lulus di sesi PEMANASAN");
    printf("\n>> Jika sesi PEMANASAN tidak lulus, maka anda tidak mengikuti sesi selanjutnya");
    printf("\n>> Poin mulai dihitung saat sesi CARI POIN");
    printf("\n>> Terdapat 12 soal. Menjawab 10 soal benar berhak mendapat 2 juta rupiah!");
    printf("\n>> Soal berbentuk pilihan ganda. Klik A, B ,C atau D untuk menjawab");
    printf("\n>> Jika jawaban benar, soal akan berlanjut.");
    printf("\n>> Jika jawaban salah, maka pertanyaan akan selesai dan score akan tertampil");
    printf("\n\n\t\t\t!!!!!!!!!!!!! SEMOGA BERUNTUNG !!!!!!!!!!!!!");
}

void hasiltertinggi(){
    system("cls");
    char nam[50];
    float nil;
    FILE *f;
    f = fopen("score.txt", "r");
    fgets(nam, 50, f);fscanf(f, "%f", &nil);
    printf("\n\n\t\t\t*************************************************************");
    printf("\n\t\t\tSelamat %s \t\t\ttelah berhasil mendapat skor tertinggi, yaitu : %.2f", nam,nil);
    printf("\n\n\t\t\t*************************************************************");
    fclose(f);
}

void edit_score(float nilai, char nama[50])
{
    system("cls");
    float ni;
    char nm[50];
    FILE *f;
    f = fopen("score.txt", "r");
    fgets(nm, 50, f);fscanf(f, "%f", &ni);
    if (nilai>ni)
    {
        ni = nilai;
        fclose(f);
        f = fopen("score.txt", "w");
        fprintf(f, "%s\n%f", nama, ni);
        fclose(f);
    }
}
