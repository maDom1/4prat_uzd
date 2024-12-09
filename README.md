# Ketvirtos užduoties kodavimo stilius

## 1. Kintamieji

### 1.1. Kintamųjų Vardai
- Kintamųjų vardai turi būti aiškūs.

- Kintamųjų vardai turi prasidėti mažąja raide.

- Naudoti anglų kalbą ir vengti santrumpų.

- Jeigu kintamasis sudaro kelis žodžius, kiekvieną kitą žodį pradėti didžiąja raide.
```c
/* OK */
int file_descriptor;
float average_score;
int printChoice;

/* Wrong */
int fd;       // Neaiški santrumpa.
float avg;    // Per trumpa santrumpa.
int printchoice; // Nėra didžiosios raidės.
```
### 1.2. Konstantų Vardai

- `#define` vardai turi būti rašomi VISOMIS DIDŽIOSIOMIS RAIDĖMIS, o const vardai turi būti rašomi kaip kintamųjų vardai.


```c
/* OK */
#define FILE_NAME_SIZE
const char* beforeVal

/* Wrong */
#define file_name_size;       // Mažos raidės
const char* beforeval         // Nėra didžiosios raidės.
```  

### 1.3. Funkcijų Vardai  

- Funkcijos pavadinimai turi būti rašomi mažosiomis raidėmis. Jeigu pavadinimas sudaro kelis žodžius, jie turi būti sujungti naudojant `_`.

```c
/* OK */
void test_create_empty_list
int main

/* Wrong */
void testcreateemptylist    // Trūksta "_"
int MAIN                    // Didžiosios raidės
```
## 2. Lygiavimo Taisyklės

### 2.1. Tarpai

- Indentacija turi būti `TAB`.

- Kiekviena nauja kodo blokų hierarchija turi būti papildoma vienu `TAB` arba **4** tarpais.

```c
/* OK */
if (value > 0) {
    printf("Positive value\n");
} else {
    printf("Non-positive value\n");
}


/* Wrong */
if (value > 0) {
printf("Positive value\n");
}else {
printf("Non-positive value\n");
}
```

### 2.2. Kodo Blokų Organizavimas

- Atidarymo `{` turi būti tame pačiame lygyje kaip ir valdymo konstrukcija (if, while, for, funkcijos deklaracija).

- Uždarymo `}` turi būti tame pačiame lygyje kaip ir atidarymo konstrukcija.
```c
/* OK */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}


/* Wrong */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
```

