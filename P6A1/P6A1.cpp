/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 04.11.2016									  */
/* Projekt: P6A1										  */
/* Beschreibung: Berechnung von pi mit Leibnis Methode	  */
/**********************************************************/

#include <stdio.h>		// Bibliotheken einbinden
#include <math.h>
#include <stdlib.h>		// f�r atoi- Funktion
#include <string.h>		// f�r strlen- Funktion
#include <ctype.h>		// f�r isDigit- Funktion

#define laengeArray 256		// Definitionen
#define konstpi 3.141593

int main(void) {		// Hauptprogramm
	double pi = 0.0, ergebnis = 0.0;		// Initialisierung
	int i = 0, n = 0, beenden = 1, wert = 0, laenge = 0, fehler = 0, summenglieder = 0;
	char eingabe[laengeArray];		// String Array

	while (beenden != 0) {		// F�hrt solange beenden den Wert 0 nicht hat, aus.
		printf("Geben sie einen Summenglied ein:\t");
		fgets(eingabe, laengeArray, stdin);		// Fuer String Eingabe. 
		fflush(stdin);
		laenge = strlen(eingabe);		// laenge von der Anzahl des Strings ausrechnen bzw herausfinden
		if (eingabe[0] == '+') {
			laenge = laenge - 2;		// laenge um 2 Stellen k�rzen wegen dem + am Anfang und \0 ganz zum Schluss
			for (i = 0; i < laenge; i++) {	// Damit man das + weg bekommt
				eingabe[i] = eingabe[i + 1];	// ersetzt die "i.te" stelle mit der "i+1.te stelle
				eingabe[i + 1] = 0;
			}
		}
		else {
			laenge--;		// laenge um 1 Stelle k�rzen wegen \0 ganz zum Schluss
		}

		for (i = 0; i < laenge; i++) {
			if (isdigit(eingabe[i]) == 0) {		// kontrolliert ob die "i.te" Stelle von dem String die Werte von 0-9 besitzt,
											// indem es eine "0" also "false" oder eine "1" also "true" als r�ckgabeparameter zur�ck gibt.
				fehler = 1;			// wenn der rueckgabeparameter von der Funktion isDigit eine 1 ist, setzt er die Variable fehler auf 1.
			}
		}
		if (fehler != 1) {		// wenn fehler nicht auf 1 gesetzt wurde f�hrt er das aus
			wert = atoi(eingabe);		// Den String Wert in einen Integer Wert umwandeln
			// printf("eingabe:\t%i\n\n", wert);
			for (i = 0; i < wert; i++) {		// Rechnung fuer pi / 4 (Formel)
				pi = pi + (pow(-1.0, (double) n)*(1.0 / (1.0 + 2.0 * (double) n)));		// dieses (double) steht f�r: f�r diese Rechnung soll der INT wert als DOUBLE 
				n++;		// inkrementiert n											// gesehen werden
			}
			pi = pi * 4.0;			// Weil das Ergebnis oben / 4 war
			printf("Zahl:\t%lf\n", pi);
			pi = 0.0;		// pi wieder zur�cksetzen
			n = 0;		// n wieder zur�cksetzen
			summenglieder = 0;	// die Anzahl der Summenglieder zur�cksetzen f�r einen zweiten Durchlauf
			ergebnis = 0;	// Zwischenspeicher zur�cksetzen f�r einen zweiten Durchlauf
			while (fabs(ergebnis - konstpi) >= (double) 0.0000005) {		// kontrolliert ob Zwischenspeicher (Ergebnis) - 3.141593 kleiner
				pi = pi + (pow(-1.0, (double)n)*(1.0 / (1.0 + 2.0 * (double)n)));		// als 0.0000005 ist und f�hrt den Befehl solange gr��er ist aus.
				n++;																	// fabs() gibt den absoluten (positiven) Wert einer Zahl zur�ck.
														// Eine positive Zahl bleibt unver�ndert, eine negative Zahl wird negiert (multipliziert mit -1).
				summenglieder++;
				ergebnis = pi * 4.0;
			}
			// printf("Kontrolle fuer pi:\t%.8f\n", ergebnis);
			pi = 0.0;		// setzt die Werte zur�ck
			n = 0;
			printf("\nDie Summenglieder bei der erstmals der\nWert von pi (also 3.141593) erreicht wurde:\t%i\n\n\n\n", summenglieder);
		}
		else {		// wenn fehler auf 1 gesetzt wurde dann f�hrt er das aus
			printf("Sie haben einen Ungueltigen Wert eingegeben.\n\n");
			fehler = 0;		// setzt den fehler Wert wieder auf 0
		}
	}
	return (1);		// rueckgabewert
}

/*
Befehle aus der folgenden Seite entnommen: https://www.proggen.org/doku.php
*/