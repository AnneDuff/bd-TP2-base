###  Basic database project

Pour cloner le project:
`git clone --recursive https://github.com/chemin.vers.repos.git`

Si jamais vous ne voyez pas zig.exe dans Tools, FoundryTools_windowsx64, faite:
`.\setup.bat`

Pour compiler le project:
`ctrl+shift+b`

Pour debugger le project:
`F5`
```mermaid
erDiagram
    CATEGORIES ||--o{ ITEMS : has
    ORDER ||--o{ CUSTOMER : has
    ORDER ||--o{ PRODUCTS : has
    ORDER ||--o{ CREDITCARD : has
    CHARACTER ||--o{ ITEMS : has
    WALLET ||--o{ CREDITCARD : has
    CUSTOMER ||--o{ CREDITCARD : has
    CUSTOMER ||--o{ CHARACTER : has
    CUSTOMER ||--o{ WALLET : has


    CHARACTER {
        INT IDCharacter PRIMARY KEY
        TEXT Name
        INT Strength
        INT Stamina
        INT Stealth
        INT Charisma
        INT Level
        TEXT Race
        TEXT Faction
        TEXT SocialStatus
        CLASS CharacterClass
    }

    ITEMS {
        INT IDItem PRIMARY KEY
        TEXT Name
        INT Value
        INT IsWeapon
        INT IsArmor
        INT IsEquipped
        INT IsSupplies
    }

    WALLET{
        ITEM Items
        INT Count
        INT Capacity
        INT GgBucksAmount
    }

    CREDITCARD{
        STRING CardInformation
    }

    CUSTOMER {
        TEXT Name
        INT ID PRIMARY KEY
        STRING Email
        STRING Adress
        TEXT Username
        TEXT Password
    }

    PRODUCTS {
        TEXT Nom
        INT IDProduct PRIMARY KEY
        FLOAT Price
        INT IsWeapon
        INT IsArmor
        INT IsSupplies
    }

    ORDER {
        INT IDOrder PRIMARY KEY
        STRING OrderNumber
    }

    CATEGORIES {
        TEXT Nom
    }
```
