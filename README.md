# get_next_line (42 School)

🇬🇧🇺🇸

This project focuses on implementing a function named get_next_line in C, which reads a file descriptor line by line. 
The primary objective is to create a reliable and efficient solution that can handle various input scenarios.
The get_next_line function is designed to read a file descriptor (fd) and return the next line from that file. The function is capable of handling different line endings, such as newline characters ('\n'). It also manages cases where lines might be split across multiple reads, ensuring accurate and complete line retrieval.

The implementation utilizes dynamic memory allocation to manage the storage of lines and partial lines efficiently.
The function reads data from the file descriptor in chunks (BUFFER_SIZE) to optimize performance and memory usage.
It identifies and handles newline characters, allowing the function to provide complete lines even if they span multiple read operations.

🇮🇹

Questo progetto si concentra sull'implementazione di una funzione chiamata get_next_line in linguaggio C, la quale legge da un descrittore di file una riga alla volta. 
L'obiettivo principale è creare una soluzione affidabile ed efficiente in grado di gestire vari scenari di input.
La funzione get_next_line è progettata per leggere un descrittore di file (fd) e restituire la successiva riga da quel file. La funzione è in grado di gestire diversi tipi di terminatori di riga, come il carattere di nuova linea ('\n'). Gestisce anche casi in cui le righe possono essere divise tra più letture, garantendo una lettura precisa e completa delle righe.

L'implementazione utilizza l'allocazione dinamica della memoria per gestire in modo efficiente lo storage delle righe e delle righe parziali.
La funzione legge i dati dal descrittore di file a blocchi (BUFFER_SIZE) per ottimizzare le prestazioni e l'uso della memoria.
Identifica e gestisce i caratteri di nuova riga, consentendo alla funzione di fornire righe complete anche se si estendono su più operazioni di lettura.

Moulinette: 125/100
<img width="935" alt="gnl" src="https://github.com/chsassi/get_next_line-42/assets/146337608/f7f735be-da03-4b30-8b4a-3be0308433ac">
