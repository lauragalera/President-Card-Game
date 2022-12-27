# President Card Game
[President](https://en.wikipedia.org/wiki/President_(card_game)) (also known as Capitalism) is a shedding card game for 3 or more, in which the players race to get rid of all of the cards in their hands in order to become "president" in the following round.

### RULES
Rules may vary from version to version. In this program, the cards are Spanish-suited cards.
<ul>
<li> The value of the cards, from highest to lowest, is twos,
aces, kings, horses, jacks, 9, 8, 7, 6, 5, 4, 3
</li>
<li> A player starts by drawing a card, pair, three or more
cards of the same number, and the following
players, in order, must draw cards of higher value, respecting the number of cards played
</li>
<li> When nobody can draw more cards, that last player starts the next turn,
rolling the cards he wants.
</li>
<li> 
This process is repeated until there are no players left.
</li>
<li>
At the end of the round, the first one to win is named
"King" (or "President" or "Capitalist" depending on the variant), the rest
up to half of the players are "Nobles", from half to the
last are "vassals" and the last is the "slave". In case there is an odd number of players, the player who is in the
central position is the "Bourgeois"
</li>
<li> Once the cards are dealt for the next round, and before playing, the "Slave" must give his best
cards to the "President", who gives him the worst ones. The first
"Noble" and the last "Vassall" also change cards, but one
less, and so on for all players except the
"Bourgeois".
</li>
</ul>

### MESSAGES

First message asks for the seed, # of players, their names and # of decks:

```
*** JOC DE L'ESCLAU ***
ENTRA LA LLAVOR:
XXX
ENTRA EL NOMBRE DE JUGADORS:
YYY
ENTRA EL NOM DEL JUGADOR/A [NUM_JUGADOR]:
ZZZ
ENTRA EL NOMBRE DE BARALLES:
BBB
```

Then, the game starts:

```
- TORN DEL JUGADOR/A [NOM_JUGADOR] –
MA:
XXX
QUINES CARTES VOLS TIRAR?
Q N
TIRADA: YYY
```

The player enters 1 1 to see the last cards played, and 0 0 to skip his turn.

By the end of the game, the ranking is displayed and there is the chance of starting a new game.

```
CLASSIFICACIO ACTUAL:
REI: [NOM_JUGADOR]
NOBLE: [NOM_JUGADOR]
BURGES: [NOM_JUGADOR]
VASSALL: [NOM_JUGADOR]
ESCLAU: [NOM_JUGADOR]
```

Before the next game, the program shows which players must swap cards, folloed by which cards they want to swap.

```
EL JUGADOR/A [NOM_JUGADOR1] I EL JUGADOR/A [NOM_JUGADOR2]
INTERCANVIEN [NUM_CARTES] CARTES

- JUGADOR/A [NOM_JUGADOR1] -
XXX
QUINES CARTES VOLS INTERCANVIAR?
X1 X2 X3...
```

And end of the game message

```
VOLS FER UNA NOVA RONDA?
XXX

*** FINAL DEL JOC ***
```

### BRIEF EXECUTION (INCOMPLETE)

```
*** JOC DE L'ESCLAU ***
ENTRA LA LLAVOR:
1234
ENTRA EL NOMBRE DE JUGADORS:
4
ENTRA EL NOM DEL JUGADOR/A 1:
PAU
ENTRA EL NOM DEL JUGADOR/A 2:
MIQUEL
ENTRA EL NOM DEL JUGADOR/A 3:
JOAN
ENTRA EL NOM DEL JUGADOR/A 4:
MATEU
ENTRA EL NOMBRE DE BARALLES:
1
- TORN DEL JUGADOR/A PAU -
MA:
[3O][4O][4E][6E][7B][8O][10C][11B][1O][1C][1B][2E]
QUINES CARTES VOLS TIRAR?
1 3
TIRADA: [3O]
- TORN DEL JUGADOR/A MIQUEL -
MA:
[5O][5C][7E][8B][9O][9C][10B][11O][11E][12C][12E][1E]
QUINES CARTES VOLS TIRAR?
1 7
TIRADA: [7E]
- TORN DEL JUGADOR/A JOAN -
MA:
[3C][3E][3B][4C][5B][6C][6B][8E][9E][9B][10O][2O]
QUINES CARTES VOLS TIRAR?
1 8
TIRADA: [8E]
- TORN DEL JUGADOR/A MATEU -
MA:
[4B][5E][6O][7O][7C][8C][10E][11C][12O][12B][2C][2B]
QUINES CARTES VOLS TIRAR?
1 10
TIRADA: [10E]
- TORN DEL JUGADOR/A PAU -
MA:
[4O][4E][6E][7B][8O][10C][11B][1O][1C][1B][2E]
QUINES CARTES VOLS TIRAR?
1 11
TIRADA: [11B]
...
EL JUGADOR/A MATEU INICIA TORN.
MA:
[12B]
QUINES CARTES VOLS TIRAR?
1 12
TIRADA: [12B]
EL JUGADOR/A MATEU HA FINALITZAT EN LA POSICIO 3.
VOLS FER UNA NOVA RONDA?
N
CLASSIFICACIO FINAL:
REI: PAU
NOBLE: MIQUEL
VASSALL: MATEU
ESCLAU: JOAN
*** FINAL DEL JOC ***
```

