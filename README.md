# itk.io

Játékszabályok
Egy hajóval vagyunk. Mint tudjuk, a hajók nem egyből reagálnak a kormányzásra, hanem késve. És minél nagyobb a hajó, annál inkább késve. 
Indulunk egy csónakkal, amit kb. késés nélkül irányítanánk, és ahogy pontokat szerzünk (pl. másokat eltalálunk), és növünk, egyre inkább késik majd az irányítás, a sebzésünk és az életünk viszont egyre nagyobb lesz. A hajó oldalán pedig ágyúk lennének, azzal lehet megölni a másikat. Első ígéretként lézerágyúk, tehát a lövés pillanatában húzunk egy egyenest, és ha eltalálta a másik hajót, akkor sebzi. A lövésnek hatósugara is van, ez is növekedhet, ahogy a hajó növekszik…
A kis hajók azért tudják majd legyőzni a nagyokat, mert mozgékonyabbak.

A játék menete
A kliensek a játék kezdetén beírják a szerver IP címét és a saját nevünket (azonos név esetén visszadob). Sikeres csatlakozás esetén a játékmenübe érünk, és onnan beléphetünk, így megjelenünk a térképen. A játék közben ESC billenytűvel öngyilkosok leszünk, ezzel a  játékmenübe kerülünk. Innen tudunk újra csatlakozni, esetleg beállítani dolgokat. 
Lesznek bizonyos információk amik játék közben folyamatosan látszanak (pl hányan vannak, ki milyen szinten van)
Külön szerver/Host
Egyenlőre dedikált szerver mellett vagyunk, mivel így a kód jobban szeparált lehet, de ebben a döntésben még segítségre lesz szükségünk.
Library-ről való döntés
Szept 27-re tudunk dönteni, egyenlőre a QT a preferált lib, a több platformon való fejlesztés lehetősége, és az elterjedtsége, és jól dokumentáltsága miatt. 
Mi mikorra lesz kész?
Hálózati kommunikáció alapjainak lefektetése - Szept 29
Szerverhez kapcsolódás, belépés, kilépés, játékosok listázása, szóval minden, ami nem a játékmechanika maga. - 
+ grafikai felület létrehozása, mindenki ugyanazt lássa a képernyőn - 
+ irányítás és lövés
Legyen játszható a játék, már csak tesztelni és csinosítani kelljen - nov 17

Feladatkörök ( még bővítjük) 
Adatszerkezetek kitalálása (milyen adatokat küldünk el, mit számol a szerver/mit számol a kliens, milyen objektumok közlekednek, mindent a szerver számol, vagy nem?)
Konkrét szabályok/szintek kitalálása(papíron)
Függvények meghatározása




