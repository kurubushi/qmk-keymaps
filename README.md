# qmk-keymaps

Install and setup:

```
$ yay -S qmk
$ qmk setup -H ~/Workspaces/qmk
```

Compile and flash:

```
$ git clone git@kurubushi/qmk-keymaps.git
$ cp -pr qmk-keymaps/crkbd "$(qmk env QMK_HOME)/keyboards/crkbd/keymaps/mymap"
$ qmk flash -kb crkbd -km mymap
```
