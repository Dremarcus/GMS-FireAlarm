# GMS-FireAlarm
Požární hlásič s odesíláním zpráv přes GSM
Použitý modul Arduino nano,NiceRF, SIM800L a Digispark
Funkce:
Čidlo kouře pošle přes NiceRF a Digispark kód ->
NiceRF příjme zprávu, kterou předá Arduino NANO ->
NANO vyhodnotí zprávu a počká až bude souhlasit počet přijatých zpráv ->
Po dosažení počtu, zapne LED a spustí sirénu ->
Následně osloví SIM800L aby poslalo SMS na tel.čísla a poté zavolal na tel.čísla ->
Poté se restartuje celé zařízení.

Dlouho jsem se pokoušel zprovoznit vícenásobné poslání SMS a Volání.
Nakonec používám před každým odesláním SMS aktivaci TEXT módu a funguje to i na xy čísel pod sebou
S voláním jsem nepochopil, proč nelze opakovat volání...
Až po nějaké době(cca2 měsíce sem tam odpoledne) jsem zkusil restartovat modul SIM800L a ejhle, ono to jede...
Takže po zavolání - reset - a před dalším voláním - start -

Použil jsem NANO ale má to nevýhodu s pamětí.
Omezení pro proměnné je jen 1kB, nevím jesti větší modul má více...
Tudíž je omezení na 2 telefonní čísla
Chtěl jsem dát 7 ale 190 bytů se mu zdá málo

Celkový program zabírá:
Projekt zabírá 9220 bytů (64%)  úložného místa pro program. Maximum je 14336 bytů.
Globální proměnné zabírají 764 bytů (74%)  dynamické paměti, 260 bytů zůstává pro lokální proměnné. Maximum je 1024 bytů.

Použitá knihovna GSMSim.h je naprosto perfektní!!! Díky erdemarslan

Přikládám Eagle DPS celého projektu
DPS je vyrobena pro krabici DLS routeru Zyxel P-660HN-T3A
Ve schématu je jen chybička- R6 je výstup na sirénu (bez odporu)
