#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <windows.h>
#include <time.h> 
void tips(); 
void soalkuis(); //untuk mendeklarasikan prosedur soalkuis
void hasiltertinggi(); //untuk mendeklarasikan prosedur hasiltertinggi
void edit_score(float, char[]); //untuk mendeklarasikan prosedur edit_score berparameter float dan char
void reset_score(); // untuk mendeklarasikan prosedur reset_score

float timed_input(char *input, float timeout, float *waktusisa) {
    float time_elapsed = 0;
    while (time_elapsed < timeout) {
        if (kbhit()) {
            *input = getch();
            *waktusisa = timeout - time_elapsed;
            return 1;
        }
        Sleep(1000);
        time_elapsed++;
    }
    *waktusisa = 0;
    return 0;
}  
void utama(){ //gerbang utama suatu program
    char pilihan, agama, elektronika, pengetahuanumum, waktusisa;
    int r1,i,n,r2,r3,r4,r5,r6,r7,r8,r9, nyawa;
    float nilai, point,score;
    char nama[50];
	tampilanmenu :
	        system("cls");
	    	printf("\t\t_________________________________");
            printf("\n\t\t|         SELAMAT DATANG        |");
            printf("\n\t\t|               DI              |");
            printf("\n\t\t|            KUIS GAME          |");
            printf("\n\t\t|_______________________________|"); 
			printf("\n\t\t            UHUUYYYY             ");           
            printf("\n\t__________________________________________________");
            printf("\n\t          Klik S untuk memulai                    ");
            printf("\n\t          Klik V untuk melihat hasil tertinggi    ");
            printf("\n\t          Klik H untuk bantuan                    ");
            printf("\n\t          Klik Q untuk keluar                     ");
            printf("\n\t          Klik R untuk mereset skor               ");
            printf("\n\t _________________________________________________");

            pilihan = getch();
            if (pilihan == 'v' || pilihan == 'V'){
                hasiltertinggi();
                getch();
                goto tampilanmenu;
            }else if (pilihan == 'h' || pilihan == 'H'){
                tips();
                getch();
                goto tampilanmenu;
            }else if (pilihan == 'q' || pilihan == 'Q'){
                exit(1);
            }else if (pilihan == 'r' || pilihan == 'R'){
        		reset_score();
        		getch();
        		goto tampilanmenu;
			}else if (pilihan == 's' || pilihan == 'S'){
                system("cls");
                printf("\n\n\n\n\n\t\tMasukkan Nama Anda : ");
                gets(nama);
                system("cls");
                printf("------------------  Selamat datang %s di KUIS PENGETAHUAN --------------------------", nama);
                printf("\n\nPilih kategori : ");
                printf("\n\nA - Agama Islam");
                printf("\n\nE - Elektronika");
				printf("\n\nP - Pengetahuan Umum");
            	pilihan = getch();
            	if (pilihan == 'a' || pilihan == 'A'){
            		goto agama;
            	}else if (pilihan == 'e' || pilihan == 'E'){
            		goto elektronika;
				}else if (pilihan == 'p' || pilihan == 'P'){
					goto pengetahuanumum;
				}else {
					goto tampilanmenu;
				}
				agama :
					system("cls");
					printf("\nAgama\n");
					printf("\n\nE - Mudah");
					printf("\n\nM - Sedang");
					printf("\n\nH - Sulit");
					pilihan = getch ();
					if (pilihan == 'e' || pilihan == 'E'){
						goto mudahAgama;
					}else if (pilihan == 'm' || pilihan == 'M'){
						goto sedangAgama;
					}else if (pilihan == 'h' || pilihan == 'H'){
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
			nyawa = 0;                	
                	for(i=1;i<=5;i++){
                		int pilihan;
                		char jawab;
                		float waktusisa;
                		system("cls");
                		r1=i;
                		switch(r1)
                		{
                		case 1:
                			printf("\n\n1. Rukun Islam ada berapa?");
                			printf("\n\nA.2\t\tB.3\n\nC.8\t\tD.5");
                			pilihan = timed_input(&jawab,10,&waktusisa);
                			if(pilihan &&(jawab == 'd' ||  jawab == 'D')){
                				printf("\n\nBenar!!");
								point+=waktusisa;
								printf("\n\nPoin kamu adalah %.2f\n\n",waktusisa);	
								getch();
								break;		
							}else{
								printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 2 :
							printf("\n\n2. Ada berapa sifat wajib Allah?");
                			printf("\n\nA.20\t\tB.18\n\nC.5\t\tD.12");
                			pilihan = timed_input(&jawab,10,&waktusisa);
                			if(pilihan &&(jawab == 'a' || jawab == 'A')){
                				printf("\n\n Benar!!");
								point+=waktusisa;
								printf("\n\nPoin kamu adalah %.2f\n\n",waktusisa);
                				getch();
                				break;
							}else{
								printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 3 :
							printf("\n\n3. Nabi dan Rasul yang terakhir adalah..");
                			printf("\n\nA.Nabi Yunus\t\tB.Nabi Yahya\n\nC.Nabi Muhammad\t\tD.Nabi Isa");
                			pilihan = timed_input(&jawab,10,&waktusisa);
                			if(pilihan && (jawab == 'c' || jawab == 'C')){
                				printf("\n\nBenar!!");
                				point+=waktusisa;
								printf("\n\nPoin kamu adalah %.2f\n\n",waktusisa);
                				getch();
                				break;
							}else{
								printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 4 :
							printf("\n\n4. Ada berapa surat dalam Al-Quran?");
                			printf("\n\nA.118\t\tB.114\n\nC.112\t\tD.120");
                			pilihan = timed_input(&jawab,10,&waktusisa);
                			if(pilihan && (jawab == 'b' || jawab == 'B')){
                				printf("\n\nBenar!!");
                				point+=waktusisa;
								printf("\n\nPoin kamu adalah %.2f\n\n",waktusisa);
                				getch();
                				break;
							}else{
								printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 5 :
							printf("\n\n5. Rukun iman yang terakhir adalah iman kepada...");
                			printf("\n\nA.Qada dan Qadar\t\tB.Kitab-Kitab Allah\n\nC.Allah\t\t\t\tD.Nabi dan Rasul");
                			pilihan = timed_input(&jawab,10,&waktusisa);
                			if(pilihan &&(jawab == 'a' || jawab == 'A')){
                				printf("\n\nBenar!!");
                				point+=waktusisa;
								printf("\n\nPoin kamu adalah %.2f\n\n",waktusisa);
                				getch();
                				goto nilai;
                				break;
							}else{
								printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								goto nilai;
								break;
							}
						}if (nyawa >= 3) {
					system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
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
                soalsedangAgama:
    			system("cls");
    			point = 0;
    			nyawa = 0;
    			for(i=1; i<=5; i++){
     		    	int pilihan;
        			char jawab;
        			float waktusisa;
        			system("cls");
        			r2 = i;
        			switch(r2) {
            		case 1:
	                	printf("\n\n1. Apa itu suudzan");
		                printf("\n\nA.Berbuat buruk\t\t\tB.Berkata buruk\n\nC.Berprasangka buruk\t\tD.Berkelakuan buruk");
		                pilihan = timed_input(&jawab, 10, &waktusisa);
		                if(pilihan && (jawab == 'c' || jawab == 'C')){
		                    printf("\n\nBenar!!");
		                    point += waktusisa;
		                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
		                    getch();
		                    break;
		                } else {
		                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
		                    nyawa++;getch();
		                    break;
		                }
		            case 2:
		                printf("\n\n2. Qudrat dalam sifat wajib Allah artinya...");
		                printf("\n\nA.Berkehendak\t\tB.Kekal\n\nC.Esa\t\t\tD.Berkuasa");
		                pilihan = timed_input(&jawab, 10, &waktusisa);
		                if(pilihan && (jawab == 'd' || jawab == 'D')){
		                    printf("\n\nBenar!!");
		                    point += waktusisa;
		                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
		                    getch();
		                    break;
		                } else {
		                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
		                    nyawa++;getch();
		                    break;
		                }
		            case 3:
		                printf("\n\n3. Al-Quran diturunkan ke bumi selama...");
		                printf("\n\nA.22 tahun 2 bulan 12 hari\t\tB.22 tahun 2 bulan 20 hari\n\nC.22 tahun 2 bulan 22 hari\t\tD.22 tahun 20 bulan 2 hari");
		                pilihan = timed_input(&jawab, 10, &waktusisa);
		                if(pilihan && (jawab == 'c' || jawab == 'C')){
		                    printf("\n\nBenar!!");
		                    point += waktusisa;
		                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
		                    nyawa++;getch();
		                    break;
		                } else {
		                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
		                    getch();
		                    break;
		                }
		            case 4:
		                printf("\n\n4. Mukjizat yang diberikan kepada Nabi Muhammad salah satunya adalah...");
		                printf("\n\nA.Al-Quran\t\t\t\tB.Tidak hangus terbakar api\n\nC.Dapat mengendalikan angin\t\tD.Dapat berbicara dengan hewan");
		                pilihan = timed_input(&jawab, 10, &waktusisa);
		                if(pilihan && (jawab == 'a' || jawab == 'A')){
		                    printf("\n\nBenar!!");
		                    point += waktusisa;
		                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
		                    getch();
		                    break;
		                } else {
		                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
		                    nyawa++;getch();
		                    break;
		                }
		            case 5:
		                printf("\n\n5. Puasa yang dilaksanakan setiap tanggal 13,14,15 adalah puasa..");
		                printf("\n\nA.Syawal\t\t\t\tB.Arafah\n\nC.Ayyamul Bidh\t\t\t\tD.Senin Kamis");
		                pilihan = timed_input(&jawab, 10, &waktusisa);
		                if(pilihan && (jawab == 'c' || jawab == 'C')){
		                    printf("\n\nBenar!!");
		                    point += waktusisa;
		                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
		                    getch();
		                    goto nilai;
		                    break;
		                } else {
		                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
		                    nyawa++;getch();
		                    goto nilai;
		                    break;
		                }
		        }if (nyawa >= 3) {
			system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
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
                soalsulitAgama:
			    system("cls");
			    point = 0;nyawa = 0;
			    for(i=1; i<=5; i++){
			        int pilihan;
			        char jawab;
			        float waktusisa;
			        system("cls");
			        r3 = i;
			        switch(r3) {
			            case 1:
			                printf("\n\n1. Apa yang dimaksud dengan konsep tauhid dalam Islam?");
			                printf("\n\nA. Percaya kepada banyak tuhan\tB. Percaya bahwa Allah adalah satu-satunya Tuhan\nC. Percaya pada reinkarnasi\tD. Percaya pada kekuatan alam");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'b' || jawab == 'B')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 2:
			                printf("\n\n2. Jelaskan konsep qadar (takdir) dalam Islam");
			                printf("\n\nA. Keyakinan bahwa semua kejadian adalah hasil usaha manusia\tB. Keyakinan bahwa semua kejadian adalah kebetulan\nC. Keyakinan bahwa semua kejadian telah ditetapkan oleh Allah\tD. Keyakinan bahwa semua kejadian adalah hasil doa");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'c' || jawab == 'C')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 3:
			                printf("\n\n3. Jelaskan arti dan pentingnya puasa Ramadan dalam agama Islam.");
			                printf("\n\nA. Bulan untuk berlibur\t\t\t\t\t\t\tB. Bulan untuk menambah rezeki\nC. Bulan untuk menahan diri dari makan, minum, dan perbuatan buruk\tD. Bulan untuk beribadah tanpa pantangan");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'c' || jawab == 'C')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 4:
			                printf("\n\n4. Bagaimana pandangan Islam tentang pernikahan dan keluarga?");
			                printf("\n\nA. Pernikahan tidak penting\t\t\t\t\t\t\tB. Keluarga bukanlah prioritas\nC. Pernikahan adalah ikatan suci dan keluarga adalah unit dasar masyarakat\tD. Pernikahan hanya untuk menghasilkan keturunan");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'c' || jawab == 'C')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    nyawa++;getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    getch();
			                    break;
			                }
			            case 5:
			                printf("\n\n5. Apa yang dimaksud dengan sunnah dalam Islam, dan bagaimana pengaruhnya dalam kehidupan umat Muslim?");
			                printf("\n\nA. Hukum wajib yang harus diikuti\t\t\t\t\t\t\t\tB. Tradisi yang ditinggalkan\nC. Tindakan, perkataan, dan persetujuan Nabi Muhammad yang menjadi contoh bagi umat Muslim\tD. Cerita rakyat yang tidak relevan");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'c' || jawab == 'C')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    goto nilai;
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    goto nilai;
			                    break;
			                }
			        }if (nyawa >= 3) {
					system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
            }
			    }
				elektronika :
					system("cls");
					printf("\nElektronika\n");
					printf("Pilih Kesulitan\n");
					printf("\n\nE - Mudah");
					printf("\n\nM - Sedang");
					printf("\n\nH - Sulit");
					pilihan = getch ();
					if (pilihan == 'e' || pilihan == 'E'){
						goto mudahElka;
					}else if (pilihan == 'm' || pilihan == 'M'){
						goto sedangElka;
					}else if (pilihan == 'h' || pilihan == 'H'){
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
                soalmudahElka:
			    system("cls");
			    point = 0;
			    nyawa = 0;
			    for(i=1; i<=5; i++){
			        int pilihan;
			        char jawab;
			        float waktusisa;
			        system("cls");
			        r4 = i;
			        switch(r4) {
			            case 1:
			                printf("\n\n1. Warna apa yang mewakili nilai 5 pada kode warna resistor?");
			                printf("\n\nA. Coklat\tB. Hijau\nC. Merah\tD. Kuning");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'b' || jawab == 'B')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 2:
			                printf("\n\n2. Berapakah nilai resistor dengan kode warna Merah, Ungu, Merah, Emas?");
			                printf("\n\nA. 2700 ohm\tB. 270 ohm\nC. 27000 ohm\tD. 270000 ohm");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'a' || jawab == 'A')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 3:
			                printf("\n\n3. Mana yang termasuk ciri-ciri rangkaian seri?");
			                printf("\n\nA. Tegangan berbeda setiap resistor\tB. Arus total sama\nC. Resistor terhubung paralel\t\tD. Semua benar");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'b' || jawab == 'B')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 4:
			                printf("\n\n4. Mana yang termasuk ciri-ciri rangkaian paralel?");
			                printf("\n\nA. Arus total sama\t\t\tB. Resistor terhubung seri\nC. Tegangan sama pada setiap resistor\tD. Tidak ada yang benar");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'c' || jawab == 'C')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
            			case 5:
                			printf("\n\n5. Berapakah nilai resistor dengan kode warna Coklat, Hitam, Merah, Perak?");
                			printf("\n\nA. 1.0 ohm\tB. 100 ohm\nC. 1000 ohm\tD. 10 ohm");
                			pilihan = timed_input(&jawab, 10, &waktusisa);
                			if(pilihan && (jawab == 'b' || jawab == 'B')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    goto nilai;
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    goto nilai;
			                    break;
			                }
			        }if (nyawa >= 3) {
					system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
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
                soalsedangElka:
			    system("cls");
			    point = 0;
			    nyawa = 0;
			    for(i=1; i<=5; i++){
			        int pilihan;
			        char jawab;
			        float waktusisa;
			        system("cls");
			        r5 = i;
			        switch(r5) {
			            case 1:
			                printf("\n\n1. Komponen apa yang digunakan untuk menyimpan muatan listrik?");
			                printf("\nA. Resistor\tB. Kapasitor\nC. Induktor\tD. Transistor");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'b' || jawab == 'B')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 2:
			                printf("\n\n2. Hukum Ohm dinyatakan dengan persamaan?");
			                printf("\nA. V = I/R\tB. I = V/R\nC. P = VI\tD. V = IR");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'd' || jawab == 'D')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 3:
			                printf("\n\n3. Alat yang digunakan untuk mengukur arus listrik adalah?");
			                printf("\nA. Voltmeter\t\tB. Ohmmeter\nC. Amperemeter\t\tD. Multimeter");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'c' || jawab == 'C')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 4:
			                printf("\n\n4. Unit dari kapasitansi adalah?");
			                printf("\nA. Ohm\t\tB. Farad\nC. Henry\tD. Coulomb");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'b' || jawab == 'B')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    break;
			                }
			            case 5:
			                printf("\n\n5. Komponen apa yang digunakan untuk mengatur aliran arus dalam satu arah?");
			                printf("\nA. Resistor\tB. Kapasitor\nC. Dioda\tD. Induktor");
			                pilihan = timed_input(&jawab, 10, &waktusisa);
			                if(pilihan && (jawab == 'c' || jawab == 'C')){
			                    printf("\n\nBenar!!");
			                    point += waktusisa;
			                    printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
			                    getch();
			                    goto nilai;
			                    break;
			                } else {
			                    printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
			                    nyawa++;getch();
			                    goto nilai;
			                    break;
			                }
			        }if (nyawa >= 3) {
					system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
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
                	nyawa = 0;
                	for(i=1;i<=5;i++){
                	int pilihan;
			        char jawab;
			        float waktusisa;
                		system("cls");
                		r6=i;
                		switch(r6)
                		{
                		case 1:
                			printf("\n\n1. Apa yang dimaksud dengan dioda?");
						    printf("\nA. Alat pengukur tegangan\t\tB. Komponen elektronik yang hanya mengizinkan arus mengalir satu arah\nC. Alat untuk mengukur resistansi\tD. Sumber listrik");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'b' || jawab == 'B')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 2 :
							printf("\n\n2. Komponen apa yang digunakan untuk menyimpan dan melepaskan muatan listrik dalam sebuah sirkuit elektronik?");
						    printf("\n\nA. Resistor\tB. Dioda\nC. Kapasitor\tD. Transistor");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 3 :
							printf("\n\n3. Apa fungsi utama transistor dalam rangkaian elektronik?");
						    printf("\n\nA. Mengukur tegangan\t\t\t\tB. Menghasilkan suara\nC. Memperkuat atau mengendalikan arus listrik\tD. Menghasilkan cahaya");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 4 :
							printf("\n\n4. Apa yang dimaksud dengan hambatan dalam elektronika?");
						    printf("\n\nA. Kemampuan untuk menghantarkan arus listrik\t\tB. Kemampuan untuk mengisolasi arus listrik\nC. Ukuran panjang sebuah kabel\t\t\t\tD. Tegangan listrik dalam sirkuit");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'a' || jawab == 'A')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 5 :
							printf("\n\n5. Berapa banyak kaki (pin) yang biasanya dimiliki oleh transistor bipolar jenis NPN?");
						    printf("\n\nA. 2\tB. 3\nC. 4\tD. 5");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'b' || jawab == 'B')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        goto nilai;
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								goto nilai;
								break;
							}
						}if (nyawa >= 3) {
					system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
            } 
					}
				pengetahuanumum :
					system("cls");
					printf("\nPengetahuan Umum\n");
					printf("Pilih Kesulitan\n");
					printf("\n\nE - Mudah");
					printf("\n\nM - Sedang");
					printf("\n\nH - Sulit");
					pilihan = getch ();
					if (pilihan == 'e' || pilihan == 'E'){
						goto mudahPu;
					}else if (pilihan == 'm' || pilihan == 'M'){
						goto sedangPu;
					}else if (pilihan == 'h' || pilihan == 'H'){
						goto sulitPu;                         
					}else{
						goto tampilanmenu;
					}
				mudahPu :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalmudahPu;
                	}
                	else {
                    goto tampilanmenu;
                }
					soalmudahPu :
                	system("cls");
                	point = 0;
                	nyawa = 0;
                	for(i=1;i<=5;i++){
                	int pilihan;
			        char jawab;
			        float waktusisa;
                		system("cls");
                		r7=i;
                		switch(r7)
                		{
                		case 1:
                			printf("\n\n1. Siapa nama presiden ketiga Indonesia?");
						    printf("\n\nA. Sukarno\t\tB. Soeharto\nC. BJ Habibie\t\tD. Abdurrahman Wahid");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 2 :
							printf("\n\n2. Apa nama planet terdekat dari matahari?");
						    printf("\n\nA. Venus\tB. Mars\nC. Bumi\t\tD. Merkurius");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'd' || jawab == 'D')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 3 :
							printf("\n\n3. Apa nama sungai terpanjang di dunia?");
						    printf("\n\nA. Sungai Amazon\tB. Sungai Nil\nC. Sungai Yangtze\tD. Sungai Mississippi");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'b' || jawab == 'B')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);\
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 4 :
							printf("\n\n4. Apa ibukota Indonesia?");
						    printf("\n\nA. Surabaya\tB. Bandung\nC. IKN\t\tD. Medan");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 5 :
							printf("\n\n5. Berapakah 5 + 7?");
						    printf("\n\nA. 10\t\tB. 11\nC. 12\t\tD. 13");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        goto nilai;
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								goto nilai;
								break;
							}
						}if (nyawa >= 3) {
					system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
            } 
					}
					sedangPu :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalsedangPu;
                	}
                	else {
                    goto tampilanmenu;
                }
					soalsedangPu :
                	system("cls");
                	point = 0;nyawa = 0;
                	for(i=1;i<=5;i++){
                	int pilihan;
			        char jawab;
			        float waktusisa;
                		system("cls");
                		r8=i;
                		switch(r8)
                		{
                		case 1:
                			printf("\n\n1. Siapa Nama Panjang Jendral Soedirman?");
						    printf("\n\nA. Hanif Soedirman\tB. Ibrahim Madara\nC. Raden Soedirman\tD. Fidel Waluyo");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 2 :
							printf("\n\n2. Kota yang dijuluki Kota Batik adalah Kota..?");
						    printf("\n\nA. Tegal\tB. Semarang\nC. Jakarta\t\tD. Pekalongan");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'd' || jawab == 'D')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 3 :
							printf("\n\n3. Apa nama gunung tertinggi di dunia?");
						    printf("\n\nA. Gunung Lawu\t\tB. Gunung Everest\nC. Gunung Kilimanjaro\tD. Gunung Jaya Wijaya");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'b' || jawab == 'B')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);\
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 4 :
							printf("\n\n4. Pulau terbesar di Indonesia adalah?");
						    printf("\nA. Jawa\t\t\tB. Sumatra\nC. Kalimantan\t\tD. Sulawesi");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 5 :
							printf("\n\n5. Lagu kebangsaan Indonesia adalah?");
						    printf("\nA. Indonesia Raya\tB. Garuda Pancasila\nC. Halo-Halo Bandung\tD. Rayuan Pulau Kelapa");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'a' || jawab == 'A')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        goto nilai;
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								goto nilai;
								break;
							}
						}if (nyawa >= 3) {
					system("cls");
	                printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
            } 
					}
					sulitPu :
					system("cls");
					tips();
                	printf("\n\n\n\nKlik Y  untuk memulai !!");
                	printf("\nKlik apapun untuk kembali ke menu!");
                	pilihan = getch();
                	if (pilihan == 'y' || pilihan == 'Y'){
                    goto soalsulitPu;
                	}
                	else {
                    goto tampilanmenu;
                }
					soalsulitPu :
                	system("cls");
                	point = 0;
                	nyawa = 0;
                	for(i=1;i<=5;i++){
                	int pilihan;
			        char jawab;
			        float waktusisa;
                		system("cls");
                		r9=i;
                		switch(r9)
                		{
                		case 1:
                			printf("\n\n1. Pada tahun berapa Revolusi Industri dimulai di Inggris?");
						    printf("\n\nA. 1600\t\tB. 1700\nC. 1800\t\tD. 1900");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'b' || jawab == 'B')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 2 :
							printf("\n\n2. Siapa nama penyair terkenal dari Jepang yang karyanya banyak digemari di seluruh dunia?");
						    printf("\n\nA. Haiku Matsuo\t\tB. RyÅnosuke Akutagawa\nC. Yasunari Kawabata\tD. Haruki Murakami");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 3 :
							printf("\n\n3. Apa nama struktur geologi yang terbentuk akibat pergerakan lempeng tektonik yang saling bertumbukan?");
						    printf("\n\nA. Gunung berapi\tB. Palung laut\nC. Pegunungan lipatan\tD. Pegunungan patahan");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'c' || jawab == 'C')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);\
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
                				nyawa++;getch();
                				break;
							}
						case 4 :
							printf("\n\n4. Apa nama penyakit yang disebabkan oleh kekurangan vitamin B12?");
						     printf("\n\nA. Anemia pernisiosa\tB. Sklerosis lateral amiotrofik (ALS)\nC. Alzheimer\t\tD. Parkinson");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'a' || jawab == 'A')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								break;
							}
						case 5 :
							printf("\n\n5. Siapa nama seniman terkenal dari Belanda yang terkenal dengan lukisannya yang menggambarkan kehidupan sehari-hari?");
						    printf("\n\nA. Vincent van Gogh\tB. Rembrandt van Rijn\nC. Johannes Vermeer\tD. Frans Hals");
						    pilihan = (timed_input(&jawab, 10, &waktusisa));
							if (pilihan && (jawab == 'b' || jawab == 'B')) {
						        printf("\n\nBenar!!");
						        point += waktusisa;
						        printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
						        getch();
						        goto nilai;
						        break;
						    } else {
						        printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
								nyawa++;getch();
								goto nilai;
								break;
							}
						}if (nyawa >= 3) {
					system("cls");
	                printf("\n\nMaaf. Kesempatan kamu sudah habis. Kamu telah menjawab salah lebih dari 3 kali.\n");
	                printf("Silahkan kembali ke menu utama...\n");
	                _getch();
	                goto tampilanmenu;
            } 
					}
                    nilai :
                        system("cls");
                        nilai=(float)point*2;
                        printf("\n\t\t\tSelamat kamu mendapat %.2f poin\n\n\n", nilai);
                        Sleep(500);
                        printf("\n\t\t\t\tYEEEYYYYY\n\n\n");
                        goto terus;

                        terus :
                            printf("\nKlik apapun untuk kembali ke menu");
                            pilihan = getch();
                            edit_score(nilai, nama);
                            goto tampilanmenu;
        
}else{
	Sleep(200);
	printf("\n\n\n\t  WOYYYY PENCET SESUAI PERINTAH LAHHHH!!!!");
	Sleep(2000);
	goto tampilanmenu;
}
}
typedef struct {
    float score;
    char name[50];
} HighscoreEntry;

void reset_score() {
	HighscoreEntry entries[3] = {{0, "-"}, {0, "-"}, {0, "-"}};
    FILE *file = fopen("score.txt", "w");
    if (file == NULL) {
        printf("Gagal mereset skor.");
    } else {
    	for(int i=0;i<3;i++){
        	fprintf(file, "%.2f %s\n", entries[i].score, entries[i].name);
        }
        printf("\n\n\t\t   Skor berhasil direset.");
    }fclose(file);
}
void hasiltertinggi() {
    FILE *file = fopen("score.txt", "r");
    if (file == NULL) {
        printf("Belum ada skor yang tersimpan.\n");
    } else {
        HighscoreEntry entries[3];
        int i;
        printf("\n\n\t\t\t*************************************************************");
        for (i = 0; i < 3; ++i) {
            fscanf(file, "%f %s", &entries[i].score, entries[i].name);
                printf("\n\t\t\t\t%d. %s \t\ttelah berhasil mendapat skor: %.2f", i + 1, entries[i].name, entries[i].score);
        }printf("\n\n\t\t\t*************************************************************");
    }fclose(file);
}
void tips(){
    printf("\n\nBantuan :  ");
    printf("\n-------------------------------------------------------------------------");
    printf("\n>> Ada 5 soal yang harus kamu jawab");
    printf("\n>> Di setiap soal akan terdapat timer selama 10 detik");
    printf("\n>> Poin di setiap soal didapat dari seberapa cepat kamu menjawab");
    printf("\n>> Poin yang kamu dapat dari setiap soal akan diakumulasikan di nilai akhir");
    printf("\n>> Soal berbentuk pilihan ganda. Klik A, B ,C atau D untuk menjawab");
    printf("\n>> Jika jawaban benar, kamu akan mendapatkan poin.");
    printf("\n>> Jika jawaban salah, kamu tidak akan mendapatkan poin");
    printf("\n\n\t\t\t!!!!!!!!!!!!! SEMANGATTT !!!!!!!!!!!!!");
}
void edit_score(float score, char nama[50]) {
    HighscoreEntry entries[3] = {{0, "-"}, {0, "-"}, {0, "-"}};
    FILE *file = fopen("score.txt", "r");
    if (file != NULL) {
        int i;
        for (i = 0; i < 3; ++i) {
            fscanf(file, "%f %s", &entries[i].score, entries[i].name);
        }fclose(file);
    }
    int i;
    for (i = 0; i < 3; ++i) {
        if (score > entries[i].score) {
            int j;
            for (j = 2; j > i; --j) {
                entries[j] = entries[j - 1];
            }
            entries[i].score = score;
            strcpy(entries[i].name, nama);
            break;
        }
    }   
    file = fopen("score.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis skor.\n");
        return;
    }
    for (i = 0; i < 3; ++i) {
        fprintf(file, "%.2f %s\n", entries[i].score, entries[i].name);
    }   
    fclose(file);
}
