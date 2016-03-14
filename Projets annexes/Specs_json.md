Voilà les deux schémas JSON pour un projet sur WebCreator et pour une page web

Reste à faire le schéma pour les modules du logiciel..


## Projet
```json
{ 
    "$schema": "http://json-schema.org/schema#",
    "title": "ProjetWebCreator",
    "description": "Structure fichier project sur WebCreator",
    "type": "object",
    "properties" : {
        "nom" : {
            "type" : "string",
            "description" : "Nom du projet"
        },
        "type" : {
            "enum" : ["projet","template"],
            "description" : "Type du projet ; un template est disponible comme modèle à la création d'un projet"
        },
        "html" : {
            "type" : "array",
            "minItems" : 0,
            "items" : { "type" : "string" },
            "uniqueItems" : true,
            "description" : "Nom des pages du projet (avec l'extension .json)"
        },
        "css" : {
            "type" : "string",
            "description" : "Lien vers le dossier css"
        },
        "font" : {
            "type" : "string",
            "description" : "Lien vers le dossier font"
        },
        "js" : {
            "type" : "string",
            "description" : "Lien vers le dossier js"
        },
        "files" : {
            "type" : "string",
            "description" : "Lien vers le dossier files, pouvant contenir des images, ou des fichiers .pdf par exemple"
        }
    }
}
```
## Page web
```json
{
    "$schema": "http://json-schema.org/schema#",
    "title": "PageWeb",
    "description": "Représentation d'une page web",
    "type": "object",  
    "properties" : {
        "page" : {
            "type" : "string",
            "description" : "Nom de la page"
        },
        "content" : {
            "$ref" : "#/definitions/html"
        }
    },
    "definitions" : {
        "html" : {
            "type" : "object",
            "description" : "Représente la balise html d'une page web",
            "properties" : {
                "head" : {
                    "$ref" : "#/definitions/head"
                },
                "body" : {
                    "$ref" : "#/definitions/body"
                }
            }
        },
        "head" : {
            "type" : "object",
            "description" : "Représente la balise head d'une page web",
            "properties" : {
                "meta" : {
                    "type":"array",
                    "minItems" : 0,
                    "items" : {"type" : "string"},
                    "uniqueItems" : true,
                    "description" : "Ensemble balises meta"
                },
                "link" : {
                    "type":"array",
                    "minItems" : 0,
                    "items" : {"type" : "string"},
                    "uniqueItems" : true,
                    "description" : "Ensemble balises link"                    
                },
                "script" : {
                    "type":"array",
                    "minItems" : 0,
                    "items" : {"type" : "string"},
                    "uniqueItems" : true,
                    "description" : "Ensemble balises script"                    
                }
            }
        },
        "body" : {
            "type" : "object",
            "description" : "Balise body d'une page web - contient tout les éléments",
            "properties" : {
                "content" : {
                    "type" : "array",
                    "minItems": 0,
                    "items" : {"$ref" : "#/definitions/element"},
                    "uniqueItems" : false,
                    "description" : "Contient tout les éléments"
                }
            }
        },
        "element": {
            "type" : "object",
            "description": "Représente un élément web",
            "properties" : {
                "id" : {
                    "type" : "string",
                    "description": "id de l'élément"
                },
                "class" : {
                    "type" : "string",
                    "description": "classe de l'élément"
                },
                "attributes" : {
                    "type" : "array",
                    "minItems" : 0,
                    "items" : { "type" : "string"},
                    "uniqueItems" : false,
                    "description" : "attributs html de l'élément"
                },
                "style" : {
                    "type" : "array",
                    "minItems" : 0,
                    "items" : { "type" : "string"},
                    "uniqueItems" : false,
                    "description" : "style CSS de l'élément"
                },
                "content" : {
                    "type" : "array",
                    "minItems": 0,
                    "items" : {"$ref" : "#/definitions/element"},
                    "uniqueItems" : false,
                    "description" : "Contient les éléments fils de l'élément ; peut être vide (ex : img)"
                }
            }
        }
    }
}
```
