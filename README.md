# RT

-- OBLIGATOIRE --

   [X] Expose
   
   [X] Les 4 objets

   [X] REM

   [X] Lumieres


-- LES OPTIONS --

   [X] Fichier de scene

   [X] Fichier ++

   [X] Lumiere d'ambiance
   
   [ ] Lumiere d'ambiance reglable dans le fichier de scene

   Objets limites :
    
    [ ] - on peut decouper basiquement les objets selon les axes x,y,z
    
    [ ] - on peut choisir de decouper au choix en position simple ou en position reelle<br>
        (un cylindre penché est soit decoupé selon son axe de revolution proprem soit selon un vrai axe)
          
    [ ] - rotations et translations fonctionnent correctement apres la decoupe
    
    [ ] - le processus de decoupe est uniaue pour tous les objets, et pas dupliqué pour chaque type d'objet
    
    [ ] - Pour le plan on peut decouper autrement que sur les axes (si vous faites une limite sur x et ym ca vous fait deja
          un carré) : un triangle, et\ou un disque par ex.
          
   Perturbations :
    
    [ ] - de la normale : genre avec un sinus, ca donne l'impression d'avoir des vaguelettes
    
    [ ] - de la couleur : un damier (qui n'a pas une double case sur l'axe des x ou des y)
    
    [ ] - de la couleur : un algo un peu plus complique que pour changer la couleur de l'objet
    
    [ ] - de la couleur : un algo super complexe, genre bruit de Perlin : comptez 2 points
    
[ ] Lumiere directe, on est éblouie par les spots en face de nous

[ ] Lumiere parallele : éclaire la scene, selon une direction precise

   Reflexion et transparence :
    
    [ ] - la reflexion marche, on a bien un effet mirroir
    
    [ ] - on peut changer le % de reflexion
    
    [ ] - la transparence fonctionne, on voit au travers
    
    [ ] - l'indice de refraction fonctionne (au besoin demander a voir la formule de Descartes dans le code)
    
    [ ] - on peut changer le % de transparence
    
[ ] - Ombre et transparence : selon la transparence d'un object, est ce que son ombre s'eclaircit/s'assombrit?

   Textures :
    
    [ ] - on peut appliquer une texture sur au moins un des 4 objets
    
    [ ] - on peut appliquer une texture sur les 4 objets
    
    [ ] - on peut attirer (ou le contraire) une texture sur un objet
    
    [ ] - on peut decaler une texture sur un objet
   
    [ ] - utilisaiton d'une lib autre que la minilibx et ses xpm pour charger les textures (jpeg, png, ..)
    
[/] - Objets composés : on peut definir un objet composé (un cube = 6 plans limités, un verre = cone,cylindre,sphere)

[X] - Objets natifs simples

 Effets visuels classiques :
    
    [ ] - antialiasing
    
    [ ] - effet cartoon
    
    [ ] - motion blur
    
    [ ] - sepia ou autre filtre de couleur
   
    [ ] - stereoscopie simple (genre lunettes rouges/vertes)
    
 Effets techniques :
    
    [ ] - calcul clister sur plusieurs machines
    
    [ ] - calcul multi thread
    
    [ ] - c'est particulierement rapide comme rendu
    
    [ ] - sauvegarde de l'image integree au RT
   
 Environnement :
    
    [ ] - interface sommaire : message d'attente graphique, barre de progression..
    
    [ ] - interface chiadee (gtk, QT, elements configurables, changer de fichier, controle du rendu
    
    [ ] - on peut effectuer des modifications de la scene en live (pos, obj, couleurs ou textures
    
    [ ] - parametrer plusieurs rendus automatiquement avec des changements d'un rendu a l'autre
   
    [ ] - generer automatiquement des objs pour une scene: torre realisé avec des spheres, helice avec sphere et cylindres
    
 Objets Exotiques :
    
    [ ] - cube troué
  
    [ ] - nappe
    
    [ ] - torre
    
    [ ] - resolution d equation fournie dans le fichier de conf
   
    [ ] - autres (objects fractals, etc..)
    
 En vrac :
    
    [ ] - sequence video realisee avec votre RT
    
    [ ] - fichiers modelers
    
    [ ] - en relief sur une TV 3D ou sur OculusRift LOL
    
    [ ] - spot non ponctuel: tel un filament d'ampoule, la source lumineuse n'est pas ponctuelle, ombres pas nettes.
   
    [ ] - d'autres trucs delirants
    
[ ] - Ruban de Moebius

[ ] - Caustics et/ou Global illumination

[ ] - C'est beau??????????????? MAGUEULE
    
