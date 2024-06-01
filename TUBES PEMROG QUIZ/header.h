#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void help();
void hasiltertinggi();
void resetskor();
void editskor(float, char[]);

typedef struct {
    char soal[500];
    char pilihan[4][100];
    char jawabanbenar;
} Pertanyaan;

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
void utama() {
    char pilihan, jawab;
    int nyawa;
    float point, nilai;
    char nama[50];

    Pertanyaan soalagamamudah[] = {
        {"Rukun Islam ada berapa?", {"A.2", "B.3", "C.8", "D.5"}, 'D'},
        {"Ada berapa sifat wajib Allah?", {"A.20", "B.18", "C.5", "D.12"}, 'A'},
        {"Nabi dan Rasul yang terakhir adalah..", {"A.Nabi Yunus", "B.Nabi Yahya", "C.Nabi Muhammad", "D.Nabi Isa"}, 'C'},
        {"Ada berapa surat dalam Al-Quran?", {"A.118", "B.114", "C.112", "D.120"}, 'B'},
        {"Rukun iman yang terakhir adalah iman kepada...", {"A.Qada dan Qadar", "B.Kitab-Kitab Allah", "C.Allah", "D.Nabi dan Rasul"}, 'A'}
        };
    int deretsoalagamamudah = sizeof(soalagamamudah) / sizeof(soalagamamudah[0]);

    Pertanyaan soalagamasedang[] = {
        {"Qudrat dalam sifat wajib Allah artinya", {"A.Berkehendak", "B.kekal", "C.esa", "D.berkuasa"}, 'D'},
        {"Al-Quran diturunkan ke bumi selama", {"A.22 tahun 2 bulan 12 hari", "B.22 tahun 2 bulan 20 hari","C.22 tahun 2 bulan 22 hari","D.22 tahun 20 bulan 2 hari"}, 'C'},
        {"Mukjizat yang diberikan kepada Nabi Muhammad salah satunya adalah?", {"A.Al-Quran","B.Tidak hangus terbakar api","C.Dapat mengendalikan angin","D.Dapat berbicara dengan hewan"}, 'A'},
        {"Puasa yang dilaksanakan setiap tanggal 13,14,15 adalah puasa", {"A.Syawal", "B.Arafah", "C.Ayyamul Bidh", "D.Senin Kamis"}, 'C'},
        {"Apa itu suudzan?", {"A.Berprasangka buruk", "B.Berbuat buruk", "C.Berprasangka baik", "D.Berbuat baik"}, 'A'}
        };
    int deretsoalagamasedang = sizeof(soalagamasedang) / sizeof(soalagamasedang[0]);

	Pertanyaan soalagamasulit[] = {
	    {"Apa yang dimaksud dengan konsep tauhid dalam Islam?", {"A.Percaya kepada banyak tuhan", "B.Percaya bahwa Allah adalah satu-satunya Tuhan", "C.Percaya pada reinkarnasi", "D.Percaya pada kekuatan alam"}, 'B'},
	    {"Jelaskan konsep qadar (takdir) dalam Islam", {"A.Keyakinan bahwa semua kejadian adalah hasil usaha manusia", "B.Keyakinan bahwa semua kejadian adalah kebetulan", "C.Keyakinan bahwa semua kejadian telah ditetapkan oleh Allah", "D.Keyakinan bahwa semua kejadian adalah hasil doa"}, 'C'},
	    {"Jelaskan arti dan pentingnya puasa Ramadan dalam agama Islam", {"A.Bulan untuk berlibur", "B.Bulan untuk menambah rezeki", "C.Bulan untuk menahan diri dari makan, minum, dan perbuatan buruk", "D.Bulan untuk beribadah tanpa pantangan"}, 'C'},
	    {"Bagaimana pandangan Islam tentang pernikahan dan keluarga?", {"A.Pernikahan tidak penting", "B.Keluarga bukanlah prioritas", "C.Pernikahan adalah ikatan suci dan keluarga adalah unit dasar masyarakat", "D.Pernikahan hanya untuk menghasilkan keturunan"}, 'C'},
	    {"Apa yang dimaksud dengan sunnah dalam Islam, dan bagaimana pengaruhnya dalam kehidupan umat Muslim?", {"A.Hukum wajib yang harus diikuti", "B.Tradisi yang ditinggalkan", "C.Tindakan, perkataan, dan persetujuan Nabi Muhammad yang menjadi contoh bagi umat Muslim", "D.Cerita rakyat yang tidak relevan"}, 'C'}
	    };
    int deretsoalagamasulit = sizeof(soalagamasulit) / sizeof(soalagamasulit[0]);
    
    Pertanyaan soalelkaez[] = {
	    {"Warna apa yang mewakili nilai 5 pada kode warna resistor?", {"A.Coklat", "B.Hijau", "C.Merah", "D.Kuning"}, 'B'},
	    {"Berapakah nilai resistor dengan kode warna Merah, Ungu, Merah, Emas?", {"A.2700 ohm", "B.270 ohm", "C.27000 ohm", "D.270000 ohm"}, 'A'},
	    {"Mana yang termasuk ciri-ciri rangkaian seri?", {"A.Tegangan berbeda setiap resistor", "B.Arus total sama", "C.Resistor terhubung paralel", "D.Semua benar"}, 'B'},
	    {"Mana yang termasuk ciri-ciri rangkaian paralel?", {"A.Arus total sama", "B.Resistor terhubung seri", "C.Tegangan sama pada setiap resistor", "D.Tidak ada yang benar"}, 'C'},
	    {"Berapakah nilai resistor dengan kode warna Coklat, Hitam, Merah, Perak?", {"A.1.0 ohm", "B.100 ohm", "C.1000 ohm", "D.10 ohm"}, 'A'}
	    };
    int deretsoalelkaez = sizeof(soalelkaez) / sizeof(soalelkaez[0]);
    
    Pertanyaan soalelkamed[] = {
	    {"Komponen apa yang digunakan untuk menyimpan muatan listrik?", {"A. Resistor", "B. Kapasitor", "C. Induktor", "D. Transistor"}, 'B'},
	    {"Hukum Ohm dinyatakan dengan persamaan?", {"A. V = I/R", "B. I = V/R", "C. P = VI", "D. V = IR"}, 'D'},
	    {"Alat yang digunakan untuk mengukur arus listrik adalah?", {"A. Voltmeter", "B. Ohmmeter", "C. Amperemeter", "D. Multimeter"}, 'C'},
	    {"Unit dari kapasitansi adalah?", {"A. Ohm", "B. Farad", "C. Henry", "D. Coulomb"}, 'B'},
	    {"Komponen apa yang digunakan untuk mengatur aliran arus dalam satu arah?", {"A. Resistor", "B. Kapasitor", "C. Dioda", "D. Induktor"}, 'C'}
	    };
    int deretsoalelkamed = sizeof(soalelkamed) / sizeof(soalelkamed[0]);

	Pertanyaan soalelkahard[] = {
	    {"Apa yang dimaksud dengan dioda?", {"A. Alat pengukur tegangan", "B. Komponen elektronik yang hanya mengizinkan arus mengalir satu arah", "C. Alat untuk mengukur resistansi", "D. Sumber listrik"}, 'B'},
	    {"Komponen apa yang digunakan untuk menyimpan dan melepaskan muatan listrik dalam sebuah sirkuit elektronik?", {"A. Resistor", "B. Dioda", "C. Kapasitor", "D. Transistor"}, 'C'},
	    {"Apa fungsi utama transistor dalam rangkaian elektronik?", {"A. Mengukur tegangan", "B. Menghasilkan suara", "C. Memperkuat atau mengendalikan arus listrik", "D. Menghasilkan cahaya"}, 'C'},
	    {"Apa yang dimaksud dengan hambatan dalam elektronika?", {"A. Kemampuan untuk menghantarkan arus listrik", "B. Kemampuan untuk mengisolasi arus listrik", "C. Ukuran panjang sebuah kabel", "D. Tegangan listrik dalam sirkuit"}, 'A'},
	    {"Berapa banyak kaki (pin) yang biasanya dimiliki oleh transistor bipolar jenis NPN?", {"A. 2", "B. 3", "C. 4", "D. 5"}, 'B'}
	    };
    int deretsoalelkahard = sizeof(soalelkahard) / sizeof(soalelkahard[0]);
    
    Pertanyaan soalpuez[] = {
	    {"Siapa nama presiden ketiga Indonesia?", {"A. Sukarno", "B. Soeharto", "C. BJ Habibie", "D. Abdurrahman Wahid"}, 'C'},
	    {"Apa nama planet terdekat dari matahari?", {"A. Venus", "B. Mars", "C. Bumi", "D. Merkurius"}, 'D'},
	    {"Apa nama sungai terpanjang di dunia?", {"A. Sungai Amazon", "B. Sungai Nil", "C. Sungai Yangtze", "D. Sungai Mississippi"}, 'B'},
	    {"Apa ibukota Indonesia?", {"A. Surabaya", "B. Bandung", "C. IKN", "D. Medan"}, 'C'},
	    {"Berapakah 5 + 7?", {"A. 10", "B. 11", "C. 12", "D. 13"}, 'C'}
	    };
    int deretsoalpuez = sizeof(soalpuez) / sizeof(soalpuez[0]);
    
	Pertanyaan soalpumed[] = {
	    {"Siapa Nama Panjang Jendral Soedirman?", {"A. Muhammad Soedirman", "B. Raden Shaleh", "C. Raden Soedirman", "D. Raden Pati"}, 'C'},
	    {"Kota yang dijuluki Kota Batik adalah Kota..?", {"A. Tegal", "B. Semarang", "C. Jakarta", "D. Pekalongan"}, 'D'},
	    {"Apa nama gunung tertinggi di dunia?", {"A. Gunung Lawu", "B. Gunung Everest", "C. Gunung Kilimanjaro", "D. Gunung Jaya Wijaya"}, 'B'},
	    {"Pulau terbesar di Indonesia adalah?", {"A. Jawa", "B. Sumatra", "C. Kalimantan", "D. Sulawesi"}, 'C'},
	    {"Lagu kebangsaan Indonesia adalah?", {"A. Indonesia Raya", "B. Garuda Pancasila", "C. Halo-Halo Bandung", "D. Rayuan Pulau Kelapa"}, 'A'}
	    };
    int deretsoalpumed = sizeof(soalpumed) / sizeof(soalpumed[0]);

	Pertanyaan soalpuhard[] = {
	    {"Pada tahun berapa Revolusi Industri dimulai di Inggris?", {"A. 1600", "B. 1700", "C. 1800", "D. 1900"}, 'B'},
	    {"Siapa nama penyair terkenal dari Jepang yang karyanya banyak digemari di seluruh dunia?", {"A. Haiku Matsuo", "B. Ryūnosuke Akutagawa", "C. Yasunari Kawabata", "D. Haruki Murakami"}, 'C'},
	    {"Apa nama struktur geologi yang terbentuk akibat pergerakan lempeng tektonik yang saling bertumbukan?", {"A. Gunung berapi", "B. Palung laut", "C. Pegunungan lipatan", "D. Pegunungan patahan"}, 'C'},
	    {"Apa nama penyakit yang disebabkan oleh kekurangan vitamin B12?", {"A. Anemia pernisiosa", "B. Sklerosis lateral amiotrofik (LS)", "C. Alzheimer", "D. Parkinson"}, 'A'},
	    {"Siapa nama seniman terkenal dari Belanda yang terkenal dengan lukisannya yang menggambarkan kehidupan sehari-hari?", {"A. Vincent van Gogh", "B. Rembrandt van Rijn", "C. Johannes Vermeer", "D. Frans Hals"}, 'B'}
	    };
    int deretsoalpuhard = sizeof(soalpuhard) / sizeof(soalpuhard[0]);
    
    tampilanmenu:
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
    if (pilihan == 'v' || pilihan == 'V') {
        hasiltertinggi();
        getch();
        goto tampilanmenu;
    } else if (pilihan == 'h' || pilihan == 'H') {
        help();
        getch();
        goto tampilanmenu;
    } else if (pilihan == 'q' || pilihan == 'Q') {
        exit(1);
    } else if (pilihan == 'r' || pilihan == 'R') {
        resetskor();
        getch();
        goto tampilanmenu;
    } else if (pilihan == 's' || pilihan == 'S') {
        system("cls");
        printf("\n\n\n\n\n\t\tMasukkan Nama Anda : ");
        gets(nama);
        system("cls");
        printf("------------------  Selamat datang %s di KUIS GAME --------------------------", nama);
        printf("\n\nPilih kategori : ");
        printf("\n\nA - Agama Islam");
        printf("\n\nE - Elektronika");
        printf("\n\nP - Pengetahuan Umum");
        pilihan = getch();
        if (pilihan == 'a' || pilihan == 'A') {
            goto agama;
        }else if (pilihan == 'e' || pilihan == 'E'){
        	goto elektronika;
		}else if (pilihan == 'p' || pilihan == 'P'){
        	goto pengetahuanumum;
		} else {
            goto tampilanmenu;
        }
    }  else {
    	Sleep(200);
	printf("\n\n\n\t  WOYYYY PENCET SESUAI PERINTAH LAHHHH!!!!");
	Sleep(2000);goto tampilanmenu;
}
agama :
    system("cls");
    printf("\nAgama\n");
    printf("\n\nE - Mudah");
    printf("\n\nM - Sedang");
    printf("\n\nH - Sulit");
    pilihan = getch();
    if (pilihan == 'e' || pilihan == 'E') {
        goto mudahAgama;
    } else if (pilihan == 'm' || pilihan == 'M'){
    	goto sedangAgama;
	}else if (pilihan == 'h' || pilihan == 'H'){
    	goto sulitAgama;
	}else {
        goto tampilanmenu;
    }
mudahAgama:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalmudahAgama;
	} else {
        goto tampilanmenu;
    }
sedangAgama:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalsedangAgama;
	} else {
        goto tampilanmenu;
    }
sulitAgama:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalsulitAgama;
	} else {
        goto tampilanmenu;
    }
soalmudahAgama:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalagamamudah; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalagamamudah[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalagamamudah[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalagamamudah[i].jawabanbenar || jawab == tolower(soalagamamudah[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;
soalsedangAgama:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalagamasedang; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalagamasedang[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalagamasedang[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalagamasedang[i].jawabanbenar || jawab == tolower(soalagamasedang[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;
	soalsulitAgama:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalagamasulit; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalagamasulit[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalagamasulit[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalagamasulit[i].jawabanbenar || jawab == tolower(soalagamasulit[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;
elektronika:
    system("cls");
    printf("\nElektronika\n");
    printf("\n\nE - Mudah");
    printf("\n\nM - Sedang");
    printf("\n\nH - Sulit");
    pilihan = getch();
    if (pilihan == 'e' || pilihan == 'E') {
        goto mudahelka;
    } else if (pilihan == 'm' || pilihan == 'M'){
    	goto sedangelka;
	}else if (pilihan == 'h' || pilihan == 'H'){
    	goto sulitelka;
	}else {
        goto tampilanmenu;
    }
mudahelka:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalmudahelka;
	} else {
        goto tampilanmenu;
    }
sedangelka:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalsedangelka;
	} else {
        goto tampilanmenu;
    }
sulitelka:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalsulitelka;
	} else {
        goto tampilanmenu;
    }
soalmudahelka:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalelkaez; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalelkaez[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalelkaez[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalelkaez[i].jawabanbenar || jawab == tolower(soalelkaez[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;
soalsedangelka:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalelkamed; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalelkamed[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalelkamed[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalelkamed[i].jawabanbenar || jawab == tolower(soalelkamed[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai; 
soalsulitelka:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalelkahard; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalelkahard[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalelkahard[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalelkahard[i].jawabanbenar || jawab == tolower(soalelkahard[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;
pengetahuanumum:
    system("cls");
    printf("\nPengetahuan Umum\n");
    printf("\n\nE - Mudah");
    printf("\n\nM - Sedang");
    printf("\n\nH - Sulit");
    pilihan = getch();
    if (pilihan == 'e' || pilihan == 'E') {
        goto mudahpu;
    } else if (pilihan == 'm' || pilihan == 'M'){
    	goto sedangpu;
	}else if (pilihan == 'h' || pilihan == 'H'){
    	goto sulitpu;
	}else {
        goto tampilanmenu;
    }
mudahpu:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalmudahpu;
	} else {
        goto tampilanmenu;
    }
sedangpu:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalsedangpu;
	} else {
        goto tampilanmenu;
    }
sulitpu:
    system("cls");
    help();
    printf("\n\n\n\nKlik Y untuk memulai !!");
    printf("\nKlik apapun untuk kembali ke menu!");
    pilihan = getch();
    if (pilihan == 'y' || pilihan == 'Y') {
        goto soalsulitpu;
	} else {
        goto tampilanmenu;
    }
soalmudahpu:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalpuez; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalpuez[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalpuez[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalpuez[i].jawabanbenar || jawab == tolower(soalpuez[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;
soalsedangpu:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalpumed; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalpumed[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalpumed[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalpumed[i].jawabanbenar || jawab == tolower(soalpumed[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;  
soalsulitpu:
    system("cls");
    point = 0;
    nyawa = 0;
    for (int i = 0; i < deretsoalpuhard; i++) {
        float waktusisa;
        system("cls");
        printf("\n\n%s", soalpuhard[i].soal);
        for (int j = 0; j < 4; j++) {
            printf("\n%s", soalpuhard[i].pilihan[j]);
        }
        int pilihan = timed_input(&jawab, 10, &waktusisa);
        if (pilihan && (jawab == soalpuhard[i].jawabanbenar || jawab == tolower(soalpuhard[i].jawabanbenar))) {
            printf("\n\nBenar!!");
            point += waktusisa;
            printf("\n\nPoin kamu adalah %.2f\n\n", waktusisa);
            getch();
        } else {
            printf("\n\nUpss!!!Kamu tidak mendapatkan poin...\n\n");
            nyawa++;
            getch();
        }
        if (nyawa >= 3) {
            system("cls");
            printf("\n\nKamu telah menjawab salah lebih dari 3 kali.\n");
            printf("Kembali ke menu utama...\n");
            getch();
            goto tampilanmenu;
        }
    }goto nilai;  
nilai:
    system("cls");
    nilai=(float)point*2;
	printf("\n\t\t\tSelamat %s kamu mendapat %.2f poin\n\n\n",nama, nilai);
    Sleep(500);
    printf("\n\t\t\t\tYEEEYYYYY\n\n\n");
    goto lanjut;
lanjut : 
    printf("\nKlik apapun untuk kembali ke menu");
    pilihan = getch();
    editskor(nilai, nama);
    goto tampilanmenu;
}
typedef struct {
    float score;
    char name[50];
} HighscoreEntry;

void resetskor() {
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
void help(){
    printf("\n\nBantuan :  ");
    printf("\n-------------------------------------------------------------------------");
    printf("\n>> Ada 5 soal yang harus kamu jawab");
    printf("\n>> Di setiap soal akan terdapat timer selama 10 detik");
    printf("\n>> Poin di setiap soal didapat dari seberapa cepat kamu menjawab");
    printf("\n>> Poin yang kamu dapat dari setiap soal akan diakumulasikan di nilai akhir");
    printf("\n>> Soal berbentuk pilihan ganda. Klik A, B ,C atau D untuk menjawab");
    printf("\n>> Jika jawaban benar, kamu akan mendapatkan poin.");
    printf("\n>> Jika jawaban salah, kamu tidak akan mendapatkan poin");
    printf("\n>> Kamu memiliki 3 kali kesempatan menjawab, jika sudah 3 kali salah maka kamu gagal");
    printf("\n>> Namun, jika kamu salah ketiga kalinya di nomor 5, kamu akan tetap mendapatkan poin");
    printf("\n\n\t\t\t!!!!!!!!!!! GOODLUCK BRE !!!!!!!!!!!!");
}
void editskor(float score, char nama[50]) {
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
