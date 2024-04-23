/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 05.11.2016									  */
/* Projekt: P6A1										  */
/* Beschreibung: Berechnung von pi mit Wallis Methode	  */
/**********************************************************/

#include <stdio.h>		// Bibliotheken einbinden
#include <math.h>
#include <stdlib.h>		// für atoi- Funktion
#include <string.h>		// für strlen- Funktion
#include <ctype.h>		// für isDigit- Funktion

#define laengeArray 256		// Definitionen
#define konstpi 3.141593

int main(void) {		// Hauptprogramm
	double pi = 0.0, ergebnis = 0.0;		// Initialisierung
	unsigned long int beenden = 1, wert = 0, laenge = 0, fehler = 0, summenglieder = 0;
	unsigned long int i = 0, n = 0;
	char eingabe[laengeArray];		// String Array

	while (beenden != 0) {		// Führt solange beenden den Wert 0 nicht hat, aus.
		printf("Geben sie einen Summenglied ein:\t");
		fgets(eingabe, laengeArray, stdin);		// Fuer String Eingabe. 
		laenge = strlen(eingabe);		// laenge von der Anzahl des Strings ausrechnen bzw herausfinden
		if (eingabe[0] == '+') {
			laenge = laenge - 2;		// laenge um 2 Stellen kürzen wegen dem + am Anfang und \0 ganz zum Schluss
			for (i = 0; i < laenge; i++) {	// Damit man das + weg bekommt
				eingabe[i] = eingabe[i + 1];	// ersetzt die "i.te" stelle mit der "i+1.te stelle
				eingabe[i + 1] = 0;
			}
		}
		else {
			laenge--;		// laenge um 1 Stelle kürzen wegen \0 ganz zum Schluss
		}

		for (i = 0; i < laenge; i++) {
			if (isdigit(eingabe[i]) == 0) {		// kontrolliert ob die "i.te" Stelle von dem String die Werte von 0-9 besitzt,
												// indem es eine "0" also "false" oder eine "1" also "true" als rückgabeparameter zurück gibt.
				fehler = 1;			// wenn der rueckgabeparameter von der Funktion isDigit eine 1 ist, setzt er die Variable fehler auf 1.
			}
		}
		if (fehler != 1) {		// wenn fehler nicht auf 1 gesetzt wurde führt er das aus
			wert = atoi(eingabe);		// Den String Wert in einen Integer Wert umwandeln
										// printf("eingabe:\t%i\n\n", wert);
			n = 2;				// weil der zähler bei 2 beginnt.
			pi = 1.0;			// weil sonst nur 0 raus kommt und der erste Wert welches berechnet werden wird != 0 sein muss. und die 1.0 lässt den Wert unverändert.
			for (i = 0; i < wert; i++) {	// Rechnung fuer pi / 2 (Formel)
				if (n % 2 == 0) {			// Fragt ob n durch 2 teilbar ist
					pi = pi * ((double)n / ((double)n - 1.0));	// Formel			// zB.: n = 2 / n = 2 - 1 = 2/1  <--- erste stelle von der Formel.
				}
			 	else {
					 pi = pi * (((double)n - 1.0) / (double)n);	// Formel			// zB.: n = 3 - 1 / n = 3 = 2/3  <--- zweite stelle von der Formel.
																					// so bekomme ich alle Stellen von der Formel problemlos ausgerechnet
				}
				n++;		// inkrementiert n wegen Anzahl der Brüche
			}
			pi = pi * 2.0;			// Weil das Ergebnis oben / 2 war
			printf("Zahl:\t%.6f\n", pi);
			n = 2;				// n auf 2 setzen
			pi = 1.0;		// pi wieder 1 setzen
			summenglieder = 0;	// die Anzahl der Summenglieder zurücksetzen für einen zweiten Durchlauf
			ergebnis = 0;	// Zwischenspeicher zurücksetzen für einen zweiten Durchlauf
			while (fabs(ergebnis - konstpi) >= 0.0000005) {		// kontrolliert ob Zwischenspeicher (Ergebnis) - 3.141593 kleiner
																// als 0.0000005 ist // fabsf macht alle Werte positiv.
				if (n % 2 == 0) {
					pi = pi * ((double)n / ((double)n - 1.0));		// Formel
				}
				else {
					pi = pi * (((double)n - 1.0) / (double)n);		// Formel
				}
				n++;
				summenglieder++;		// zählt Summenglieder hoch wie oft die Schleife durchgeführt also
				ergebnis = pi * 2.0;	// zum überprüfen ob der Wert pi erreicht wurde (Zwischenspeicher)
			}
			// printf("Kontrolle fuer pi:\t%.8f\n", ergebnis);

			printf("\nDie Summenglieder bei der erstmals der\nWert von pi (also 3.141593) erreicht wurde:\t%i\n\n\n\n", summenglieder);
		}
		else {		// wenn fehler auf 1 gesetzt wurde dann führt er das aus
			printf("Sie haben einen Ungueltigen Wert eingegeben.\n\n");
			fehler = 0;		// setzt den fehler Wert wieder auf 0
		}
	}
	return (1);		// rueckgabewert
}

/*
Befehle aus der folgenden Seite entnommen: https://www.proggen.org/doku.php zB.: fabs. Man könnte es aber auch mal -1 machen wenn der Wert kleiner 0 ist und würde das Selbe raus kriegen.
Formel für die Wallis Methode: http://matheguru.com/allgemein/230-kreiszahl-pi.html
*/