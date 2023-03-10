#include <stdio.h>
#include <stdlib.h>

double permintaan, persediaan;
double out_r1,out_r2,out_r3,out_r4;
float r1,r2,r3,r4;
double pmta = 500, pmtb = 6000;
double psda = 200, psdb = 800;
double A, B, deff;

float pmt_turun(double a, double b){
if (permintaan <= a){return 1;}
else if (permintaan > a && permintaan < b){return (b - permintaan) / (b - a);}
else if (permintaan >= b) { return 0;}
}

float pmt_naik(double a, double b){
if (permintaan <= a){return 0;}
else if (permintaan > a && permintaan < b){return (permintaan - a) / (b - a);}
else if (permintaan >= b) { return 1;}
}

float prsd_sedikit(double a, double b){
if (persediaan <= a){return 1;}
else if (persediaan > a && persediaan < b){return (b - persediaan) / (b - a);}
else if (persediaan >= b) { return 0;}
}

float prsd_banyak(double a, double b){
if (persediaan <= a){return 0;}
else if (persediaan > a && persediaan < b){return (persediaan - a) / (b - a);}
else if (persediaan >= b) { return 1;}
}

float min(float a, float b){
if (a < b){return a;}
else if (b < a){ return b;}
else {return a;}
}

void rule (double prdsA, double prdsB){
// IF Permintaan TURUN And Persediaan BANYAK
//THEN Produksi Barang BERKURANG;
r1 = min(pmt_turun(pmta,pmtb), prsd_banyak(psda,psdb));
 out_r1= prdsB - ((prdsB - prdsA) * r1) ;
// IF Permintaan TURUN And Persediaan SEDIKIT
//THEN Produksi Barang BERKURANG;
r2 = min(pmt_turun(pmta,pmtb), prsd_sedikit(psda,psdb));
 out_r2 = prdsB - ((prdsB - prdsA) * r2) ;
// IF Permintaan NAIK And Persediaan BANYAK
//THEN Produksi Barang BERTAMBAH;
r3 = min(pmt_naik(pmta,pmtb), prsd_banyak(psda,psdb));
 out_r3 = 3000 + ((prdsB - prdsA) * r3);
// IF Permintaan NAIK And Persediaan SEDIKIT
// Produksi Barang BERTAMBAH;
r4 = min(pmt_naik(pmta,pmtb), prsd_sedikit(psda,psdb));
 out_r4 = 3000 + ((prdsB - prdsA) * r4);

 A = (r1*out_r1) + (r2*out_r2) + (r3*out_r3) + (r4*out_r4);
 B = r1+r1+r3+r4;

 deff = A/B;
}

int main()
{
    printf("Masukan Permintaan :");
    scanf("%lf", &permintaan);
    printf("Masukan Persediaan :");
    scanf("%lf", &persediaan);

    rule (3000, 9000);

    printf("Keanggotaan Pmt_Turun = %lf\n", pmt_turun(pmta, pmtb));
    printf("Keanggotaan Pmt_Naik = %lf\n", pmt_naik(pmta, pmtb));
    printf("Keanggotaan Prsd_Sedikit = %lf\n", prsd_sedikit(psda, psdb));
    printf("Keanggotaan Prsd_Banyak = %lf\n", prsd_banyak(psda, psdb));

    printf("u Rule 1 = %lf\n", r1);
    printf("u Rule 2 = %lf\n", r2);
    printf("u Rule 3 = %lf\n", r3);
    printf("u Rule 4 = %lf\n", r4);

    printf("Out Rule 1 = %lf\n", out_r1);
    printf("Out Rule 2 = %lf\n", out_r2);
    printf("Out Rule 3 = %lf\n", out_r3);
    printf("Out Rule 4 = %lf\n", out_r4);

    printf("\n\n DEFUZZY = %lf", deff);

    return 0;
}
