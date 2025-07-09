# qmk-keymaps

Install and setup:

```
$ yay -S qmk
$ qmk setup -H ~/Workspaces/qmk
```

Compile and flash:

```
$ git clone git@kurubushi/qmk-keymaps.git
$ ln -s "$(pwd)/qmk-keymaps/crkbd" "$(qmk env QMK_HOME)/keyboards/crkbd/keymaps/mymap"
$ qmk flash -kb crkbd -km mymap
```

I have confirmed with qmk 1.1.8.
