/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 04.11.2016									  */
/* Projekt: P6A1										  */
/* Beschreibung: Berechnung von pi mit Leibnis Methode	  */
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
	int i = 0, n = 0, beenden = 1, wert = 0, laenge = 0, fehler = 0, summenglieder = 0;
	char eingabe[laengeArray];		// String Array

	while (beenden != 0) {		// Führt solange beenden den Wert 0 nicht hat, aus.
		printf("Geben sie einen Summenglied ein:\t");
		fgets(eingabe, laengeArray, stdin);		// Fuer String Eingabe. 
		fflush(stdin);
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
			for (i = 0; i < wert; i++) {		// Rechnung fuer pi / 4 (Formel)
				pi = pi + (pow(-1.0, (double) n)*(1.0 / (1.0 + 2.0 * (double) n)));		// dieses (double) steht für: für diese Rechnung soll der INT wert als DOUBLE 
				n++;		// inkrementiert n											// gesehen werden
			}
			pi = pi * 4.0;			// Weil das Ergebnis oben / 4 war
			printf("Zahl:\t%lf\n", pi);
			pi = 0.0;		// pi wieder zurücksetzen
			n = 0;		// n wieder zurücksetzen
			summenglieder = 0;	// die Anzahl der Summenglieder zurücksetzen für einen zweiten Durchlauf
			ergebnis = 0;	// Zwischenspeicher zurücksetzen für einen zweiten Durchlauf
			while (fabs(ergebnis - konstpi) >= (double) 0.0000005) {		// kontrolliert ob Zwischenspeicher (Ergebnis) - 3.141593 kleiner
				pi = pi + (pow(-1.0, (double)n)*(1.0 / (1.0 + 2.0 * (double)n)));		// als 0.0000005 ist und führt den Befehl solange größer ist aus.
				n++;																	// fabs() gibt den absoluten (positiven) Wert einer Zahl zurück.
														// Eine positive Zahl bleibt unverändert, eine negative Zahl wird negiert (multipliziert mit -1).
				summenglieder++;
				ergebnis = pi * 4.0;
			}
			// printf("Kontrolle fuer pi:\t%.8f\n", ergebnis);
			pi = 0.0;		// setzt die Werte zurück
			n = 0;
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
Befehle aus der folgenden Seite entnommen: https://www.proggen.org/doku.php
*/