CREATE TABLE IF NOT EXISTS Personnage(
    Nom TEXT,
    Race TEXT,
    Faction TEXT,
    SocialStatus TEXT,
    Class TEXT
);

CREATE TABLE IF NOT EXISTS Objet(
    Nom TEXT,
    Price FLOAT,
    isWeapon INT,
    isArmor INT,
    isEquipped INT
);

CREATE TABLE IF NOT EXISTS Categorie(
    Nom TEXT,
);

CREATE TABLE IF NOT EXISTS Commande(
    ID INT,
    OrderNumber INT,
);

CREATE TABLE IF NOT EXISTS Produit(
    Nom TEXT,
    ID INT,
    Price FLOAT
);

CREATE TABLE IF NOT EXISTS Client(
    Nom TEXT,
    ID INT,
    Email TEXT,
    CardNumber INT,
    CardCVV int
);