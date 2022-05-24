Program rozwiazujacy problem czesciowego trawienia enzymami restrykcyjnymi.

Problem mapowania metodą częściowego trawienia bazuje na wynikach eksperymentu z jednym enzymem restrykcyjnym tnącym kopie badanego fragmentu DNA w odpowiadających mu miejscach restrykcyjnych, lecz w różnych przedziałach czasowych. Czas trwania trawienia enzymem (w teoretycznym modelu eksperymentu) dobierany jest w kolejnych reakcjach w taki sposób, aby enzym przeciął fragment DNA odpowiednio w jednym, w dwóch, itd., w końcu we wszystkich miejscach restrykcyjnych obecnych w tym fragmencie. W rezultacie otrzymujemy multizbiór A długości odcinków uzyskanych we wszystkich takich reakcjach, uzupełniony o długość całego fragmentu. Należy odtworzyć obraz (mapę) miejsc restrykcyjnych w badanym fragmencie na podstawie wyników tego eksperymentu, czyli takie rozmieszczenie cięć, że odległości pomiędzy wszystkimi parami cięć (a także końcami fragmentu DNA) pokryją się z multizbiorem A.
Przykład: A = {2, 3, 3, 4, 6, 6, 7, 8, 9, 9, 11, 12, 15, 15, 18}. Mapa = (3, 4, 2, 6, 3).

Multizbior A nalezy wprowadzic do pliku 'instancja.txt'. Przykladowa instancje mozna znalezc w folderze 'instancje'. W folderze tym znajduje sie tez prosty skrypt w Pythonie do losowego generowania instancji w zaleznosci od liczby ciec enazymem restrykcyjnym. Mapa, ktora pokaze skrypt do generowania instancji moze byc w innej kolejnosci niz mapa znaleziona przez glowny program.

Program zrealizowany w ramach laboratorium "Algorytmy Kombinatoryczne w Bioinformatyce" prowadzonym przez prof. Martę Kasprzak. 

Uzyty fragment opisu problemu oraz szkielet funkcji szukajacej mapy w sposob rekurenycjny pochodzi ze strony prof. Marty Kasprzak.