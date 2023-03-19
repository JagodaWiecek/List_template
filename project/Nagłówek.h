#ifndef NAG£ÓWEK_H
#define NAG£ÓWEK_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

template<typename T>
class Element { ///klasa element
	template<typename U> friend class List; ///zaprzyjazniona klasa List
	T data; ///zmienna typu T
	shared_ptr<Element<T>> next; ///wskaznik na kolejny element typu T

public:

    Element(T data) ; ///Konstuktor jednoargumentowy
	~Element() {} ; ///Destruktor klasy 

	void add(T data); ///Funkcja dodaj¹ca obiekt typu T do listy 
	T& get(unsigned int n); ///Funkcja do uzyskania obiektu tupu T z listy o indeksie n
	const T& get(unsigned int n)const; ///Funkcja do uzyskania obiektu tupu T z listy o indeksie n
	int size() const; ///Funkcja do uzyskania liczby calkowitej, ile jest elementow w liscie 
	void erase(unsigned int n);  ///Funckja ktora usuwa wskaznik na element o indeksie n
	void swap(); ///Funckja zamieniajaca elementy ze soba, wykorzystywana do sortowania w klasie List
	
};

template<typename T>
class List
{
	shared_ptr<Element<T>> first; ///Wskaznik na pierwszy element

public:
	List() : first(nullptr) {}; ///Konstruktor bezargumentowy
	List(const initializer_list<T>); ///Konstruktor wieloargumentowy
	List(const List& datas); //Konstruktor kopiuj¹cy
	List( List&& datas); ///Konstruktor przenosz¹cy
	~List() {}; ///Destruktor klasy

	void add(T data); ///Funkcja dodaj¹ca obiekt typu T do listy
	T& get(unsigned int n); ///Funkcja do uzyskania obiektu tupu T z listy o indeksie n
	const T& get(unsigned int n) const;///Funkcja do uzyskania obiektu tupu T z listy o indeksie n
	int size()const; ///Funkcja do uzyskania liczby calkowitej, ile jest elementow w liscie 
	void erase(unsigned int n);///Funckja ktora usuwa wskaznik na element o indeksie n
	void sort(); ///Funkcja sortowania dla listy. Oparta jest na sortowaniu babelkowym
	List& operator=(const List& other); ///Operator przypisania
	List& operator=(List&& other); ///Operator przepisania
	void serialization(const string& nazwa); ///Funckja do zapisywania do pliku binarnie
	void deserialization(const string& nazwa);///Funckja do odczytywania z pliku binarnie
};

class student ///Klasa danych o studentach
{
	string PESEL; //zmienna typu string, pesel, glowna zmienna w programie, ktora laczy klase "student" z klasa "oceny"
	string imie, nazwisko; ///zmienna typu string, dane imie i nazwisko studentow
	string data; ///zmienna typu string, data urodzenia studenta
	string adres, nr_mieszkania, miasto; ///zmienne typu string, adres zamieszkania, numer mieszkania oraz nazwa miasta
public:
	student() {}; ///konstruktor bezargumentowy
	student(string& pesel,string& imie,string& nazwisko, string& data,string& adres,string& mieszkanie, string& miasto); ///konstruktor wieloargumentowy
	void SetPESEL(const string& pesel); ///Funkcja do ustawienia zmiennej "pesel"
	void SetImie(const string& imie); ///Funkcja do ustawienia zmiennej "imie"
	void SetNazwisko(const string& nazwisko); ///Funkcja do ustawienia zmiennej "nazwisko"
	void SetData(const string& data); ///Funkcja do ustawienia zmiennej "data"
	void SetAdres(const string& adres); ///Funkcja do ustawienia zmiennej "adres"
	void SetNR_mieszkania(const string& mieszkanie); ///Funkcja do ustawienia zmiennej "nr_mieszkania"
	void SetMiasto(const string& miasto); ///Funkcja do ustawienia zmiennej "miat=sti"

	string GetPesel(); ///Funkcja do uzyskania zmiennej "pesel"
	string GetImie(); ///Funkcja do uzyskania zmiennej "imie"
	string GetNazwisko(); ///Funkcja do uzyskania zmiennej "nazwisko"
	string GetData(); ///Funkcja do uzyskania zmiennej "data"
	string GetAdres(); ///Funkcja do uzyskania zmiennej "adres"
	string GetNR_mieszkania(); ///Funkcja do uzyskania zmiennej "nr_mieszkania"
	string GetMiasto(); ///Funkcja do uzyskania zmiennej "miasto"

	void print(ostream& out); ///funckja do drukowania zmiennych klasy na wybrany strumien 

	bool operator > (const student& cmp)const //operator porownania dla klasy student. Jest potrzebna do funkcji sortowania w liscie, gdzie jest sortowana po peselu
	{
		return student::PESEL > cmp.PESEL;
	}
};

class oceny
{
	string PESEL; ///zmienna typu string, pesel, glowna zmienna w programie, ktora laczy klase "student" z klasa "oceny"
	string przedmiot;///zmienna typu string,
	double ocena;///zmienna typu double 
	string zadanie;///zmienna typu string,

public:
	oceny() {}; ///konstruktor bezargumentowy
	oceny(string& pesel, string& przedmiot, double& ocena, string& zadanie); ///konstruktor wieloargumentowy
	void SetPESEL(const string& pesel); ///Funkcja do ustawienia zmiennej "pesel"
	void SetPrzedmiot(const string& przedmiot); ///Funkcja do ustawienia zmiennej "przedmiot"
	void SetOcena(const double& ocena); ///Funkcja do ustawienia zmiennej "ocena"
	void SetZadanie(const string& zadanie); ///Funkcja do ustawienia zmiennej "zadanie"

	string GetPESEL();///Funkcja do uzyskania zmiennej "pesel"
	string GetPrzedmiot();///Funkcja do uzyskania zmiennej "przedmiot"
	double GetOcena();///Funkcja do uzyskania zmiennej "ocena"
	string GetZadanie();///Funkcja do uzyskania zmiennej "zadanie"

	void print(ostream& out); ///funckja do drukowania zmiennych klasy na wybrany strumien 

	bool operator > (const oceny& cmp)const { //operator porownania dla klasy oceny. Jest potrzebna do funkcji sortowania w liscie, gdzie jest sortowana po peselu
		return oceny::PESEL > cmp.PESEL;
	}
};

template class List<int>;
template class List<string>;
template class List<double>;
template class List<student>;
template class List<oceny>;

//--------------------------------------
///Funkcja sluzy do wprowadzenia zmiennych z pliku do listy
///List<student>& l : lista zmiennych klasy student do której bed¹ wprowadzane zmienne z pliku
/// string osoby : nazwa pliku w którym znajduj¹ sie dane o uczniach 
void wpisz1(List<student>& l, string osoby);
///Funkcja sluzy do wprowadzenia zmiennych z pliku do listy
///List<oceny>& l : lista zmiennych klasy oceny do której bed¹ wprowadzane zmienne z pliku
/// string opis : nazwa pliku w którym znajduj¹ sie dane o ocenach uczniow 
void wpisz2(List<oceny>& l, string opis);
/// Funkcja zwracaj¹ca wartosc double, ktora jest srednia "pojedynczej osoby" z jednego przedmiotu
/// string id : jest to pesel po ktorej identyfikuje sie uczniow
/// string przedmiot : jest to konkretny przedmiot, z ktorego jest zwracana ocena srednia
/// List<oceny> o : lista w ktorej znajduja sie wszystkie dane, oceny, pesele i przedmioty. Po niej w petlach for sa sprawdzane i dodawane do sumy oceny by potem obliczyc z nich srednia
double sredniaUcznia(string id, string przedmiot, List<oceny> o);
///Funkcja do uzupelnienia listy zmiennych typu string by wyciagnac, jakie przedmioty sa w pliku z ocenami
/// List<oceny> O : w liscie znajduja sie wszystkie informacje o ocenach
/// List<string>& przed : lista ktora na poczatku jest pusta, poprzez petle for jest sprawdzane czy w liscie znajduje sie przedmiot lekcyjny. Jesli nie, to jest dopisywany do listy
void ListaPrzedmiotow(List<oceny> O, List<string>& przed);
///Funkcja do obliczenia srednich ocen z konkretnych przedmiotow, ktora pozniej zapisywala je w pliku wyjsciowym
///List<student>& s : lista klasy student, w ktorej znajduja sie informacje o uczniach
/// List<oceny>& O : lista klasy oceny, w ktorej znajduja sie informacje o ocenach studentow
/// ofstream& in : plik wyjsciowy, do ktorego sa zapisywane oceny koncowe
void srednia(List<student>& s, List<oceny>& O, ofstream& in);
/// <summary>
/// Funkcja do wyliczenia sredniej szkoly na podstawie ocen koncowych uczniow
/// </summary>
/// <param name="s">lista klasy student, by uzyskac informacje o uczniach</param>
/// <param name="O">lista klasy oceny, by uzyskac informacje o ocenach uczniow</param>
/// <param name="srednia">wartosc sredniej szkoly, do ktorej bedzie zapisywana wyliczona wartosc</param>
void SredniaSzkoly(List<student>& s, List<oceny>& O, double& srednia);
/// <summary>
/// Funkcja do wyliczenia sredniej ogolnej z wszystkich przedmiotow
/// </summary>
/// <param name="s">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="O">lista klasy oceny, by uzyskac informacje o ocenach uczniow</param>
/// <param name="idx">zmienna typu calkowitego, indeks by funkcja od razu korzystala z konkretnego elementu w tablicy</param>
/// <returns>funkcja zwraca srednia ucznia zwszystkich przedmiotow</returns>
double SredniaUcznia(List<student>& s, List<oceny>& O, int idx);
/// <summary>
/// Funkcja do wpisania wyliczonych danych do pliku wyjsciowego
/// </summary>
/// <param name="s">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="O">lista klasy oceny, by uzyskac informacje o ocenach uczniow</param>
/// <param name="in"> plik wyjsciowy, do ktorego sa zapisywane oceny koncowe szkoly i uczniow</param>
void sredniaOgolna(List<student>& s, List<oceny>& O, ofstream& in);
/// <summary>
/// Funkcja do sprawdzenia, jakie sa roczniki w danej liscie
/// </summary>
/// <param name="s">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="Roczniki">lista typu string, do ktorej sa zapisywane wszystkie roczniki</param>
void IleRocznikow(List<student>& s, List<string>& Roczniki);
/// <summary>
/// Funkcja do wypisania do pliku wyjsciowego osoby w jednym roczniku
/// </summary>
/// <param name="S">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="in">plik wyjsciowy, do ktorego sa zapisywane odoby po tym samym roku urodzenia</param>
void WspolnyRok(List<student>& S, ofstream& in); 
/// <summary>
/// Funkcja do sprawdzenia, z jakich roznych miast pochodza uczniowe
/// </summary>
/// <param name="S">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="miasto">lista typu string do przechowywania informacji o miastach</param>
void Miasta(List<student>& S, List<string>& miasto);
/// <summary>
/// Funkcja wpisujaca do pliku wyjsciowego studentow po wspolnych miejscach zamieszkania
/// </summary>
/// <param name="S">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="in">plik wyjsciowy, do ktorego sa zapisywane osoby po tym samym miejscu zamieszkania</param>
void WspolnaMiasto(List<student>& S, ofstream& in);
/// <summary>
/// Funkcja do sprawdzenia, jakie sa ulice, na ktorych mieszkaja uczniowie
/// </summary>
/// <param name="S">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="ulice">lista typu string, ktora przechowuje informacje na temat ulic</param>
void Ulica(List<student>& S, List<string>& ulice);
/// <summary>
/// Funkcja, ktora wpisuje studentow, pogrupowanych po ulicach zamieszkania, zwracajac uwage na odmienne miasta
/// </summary>
/// <param name="S">lista klasy student, w ktorej sa informacje o uczniach</param>
/// <param name="in">plik wyjsciowy, do ktorego sa zapisywane osoby po tym samym miejscu zamieszkania</param>
void WspolnaUlica(List<student>& S, ofstream& in);
/// <summary>
/// Funkcja do wyswietlenia menu na poczatku programu
/// </summary>
void Wyswietlacz();
/// <summary>
/// funkcja do wlaczenia programu
/// </summary>
/// <param name="osoby">nazwa pliku, ktory zawiera informacje o uczniach</param>
/// <param name="opis">nazwa pliku, ktory zawiera informacje o ocenach uczniow</param>
/// <param name="wyj">nazwa pliku wyjsciowego, do ktorego beda wpisane wygenerowane informacje</param>
void menu(string& osoby, string& opis, string& wyj);
#endif