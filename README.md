#高エネルギー宇宙物理学のための ROOT 入門

『高エネルギー宇宙物理学のための ROOT 入門』は素粒子物理学、宇宙線物理学、X 線・ガンマ線天文学などを研究する学部生や大学院生を対象にした ROOT の入門書です（2016 年 2 月現在、大部分がまだまだ執筆途中です）。本書は LaTeX で書かれており、全ての C++、LaTeX、Python のソースコードが GitHub 上で公開されています。

##PDF の入手方法

####git を使う
最新版の LaTeX ファイルを GitHub から入手して `platex` と `dvipdfmx` コマンドで `RHEA.pdf` を生成してください。

```
$ git clone https://github.com/akira-okumura/RHEA.git
$ cd RHEA
$ ls
Makefile  README.md RHEA.tex  fig       src       tex
$ make
$ ls
Makefile  RHEA.aux  RHEA.log  RHEA.pdf  RHEA.toc  src
README.md RHEA.dvi  RHEA.out  RHEA.tex  fig       tex
```

OS X 10.9 上の MacPorts で導入した `texlive-lang-japanese @34224_0+doc` で動作確認をしています。

もし GitHub 上の repository で更新があった場合は、以下のように更新してください。`git pull` コマンドが GitHub 上にある最新のファイルを取得します。

```
$ cd RHEA
$ git pull
$ make
```

####生成済みの PDF を落とす

もしくは、生成済みの PDF を https://github.com/akira-okumura/RHEA/releases から入手してください。ただし最新版である保証はありません。PDF 表紙の日付をよく確認してください。 

##改訂の要望
もし本書の内容に誤りや不足箇所を見つけられた場合、もしくは追加してほしい項目がある場合、https://github.com/akira-okumura/RHEA/issues から issue を新規作成してお知らせ下さい。GitHub のアカウント作成が必要です。

GitHub の使い方をご存知の場合、pull request してくださってももちろん構いません。

もちろんメールや Twitter でご連絡いただいても構いませんが、他の方にも内容が見えるように、GitHub経由での連絡が望ましいです。

##著者について
名古屋大学宇宙地球環境研究所の[奥村曉](http://www.isee.nagoya-u.ac.jp/~okumura/profile.html)が執筆しています。ROOT の専門家ではありませんが、ROOT を使った光線追跡（光学系シミュレーション）のライブラリ（[ROBAST](http://robast.github.io/)）の開発をやったりしています。

#### 連絡先
- oxon@mac.com
- Twitter: [@akiraokumura](https://twitter.com/akiraokumura)
- GitHub: [akira-okumura](https://github.com/akira-okumura/)
- Blog: http://oxon.hatenablog.com/
