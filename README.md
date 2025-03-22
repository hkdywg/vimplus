<p align="center">
<img src="./doc/logo.png">
</p>

An automatic configuration program for vim
===============================================



## 安装vimplus

    git clone https://github.com/hkdywg/vimplus.git ~/.vimplus
    cd ~/.vimplus
    ./install.sh

## 插件列表

| 插件                                | 说明                                                                           |
| -------                             | -----                                                                          |
| [cpp-mode][58]                      | 提供生成函数实现、函数声明/实现跳转、.h .cpp切换等功能(I'm author:smile:)      |
| [vim-edit][72]                      | 方便的文本编辑插件(I'm author:smile:)                                          |
| [change-colorscheme][27]            | 随心所欲切换主题(I'm author:smile:)                                            |
| [prepare-code][67]                  | 新建文件时，生成预定义代码片段(I'm author:smile:)                              |
| [vim-buffer][70]                    | vim缓存操作(I'm author:smile:)                                                 |
| [vimplus-startify][66]              | vimplus开始页面(修改自[mhinz/vim-startify][25])                                |
| [tagbar][13]                        | 使用[majutsushi/tagbar][13]的v2.3版本，[taglist][14]的替代品，显示类/方法/变量 |
| [vim-plug][4]                       | 比[Vundle][54]下载更快的插件管理软件                                           |
| [YouCompleteMe][5]                  | 史上最强大的基于语义的自动补全插件，支持C/C++、C#、Python、PHP等语言           |
| [NerdTree][6]                       | 代码资源管理器                                                                 |
| [vim-nerdtree-syntax-highlight][52] | NerdTree文件类型高亮                                                           |
| [nerdtree-git-plugin][53]           | NerdTree显示git状态                                                            |
| [vim-devicons][15]                  | 显示文件类型图标                                                               |
| [Airline][8]                        | 可以取代[powerline][9]的状态栏美化插件                                         |
| [auto-pairs][10]                    | 自动补全引号、圆括号、花括号等                                                 |
| [LeaderF][56]                       | 比[ctrlp][12]更强大的文件的模糊搜索工具                                        |
| [ack][62]                           | 强大的文本搜索工具                                                             |
| [vim-surround][16]                  | 自动增加、替换配对符的插件                                                     |
| [vim-commentary][17]                | 快速注释代码插件                                                               |
| [vim-repeat][18]                    | 重复上一次操作                                                                 |
| [vim-endwise][19]                   | if/end/endif/endfunction补全                                                   |
| [tabular][20]                       | 代码、注释、表格对齐                                                           |
| [vim-easymotion][23]                | 强大的光标快速移动工具，强大到颠覆你的插件观                                   |
| [incsearch.vim][24]                 | 模糊字符搜索插件                                                               |
| [vim-fugitive][36]                  | 集成Git                                                                        |
| [gv][64]                            | 显示git提交记录                                                                |
| [vim-slash][50]                     | 优化搜索，移动光标后清除高亮                                                   |
| [echodoc][57]                       | 补全函数时在命令栏显示函数签名                                                 |
| [vim-smooth-scroll][60]             | 让翻页更顺畅                                                                   |
| [clever-f.vim][68]                  | 强化f和F键                                                                     |


## 常用快捷键

以下是部分快捷键，可通过vimplus的`,h`命令查看[vimplus帮助文档][59]。

| 快捷键              | 说明                                      |
| -------             | -----                                     |
| `,`                 | Leader Key                                |
| `<leader>n`         | 打开/关闭代码资源管理器                   |
| `<leader>t`         | 打开/关闭函数列表                         |
| `<leader>a`         | .h .cpp 文件切换                          |
| `<leader>u`         | 转到函数声明                              |
| `<leader>U`         | 转到函数实现                              |
| `<leader>u`         | 转到变量声明                              |
| `<leader>o`         | 打开include文件                           |
| `<leader>y`         | 拷贝函数声明                              |
| `<leader>p`         | 生成函数实现                              |
| `<leader>w`         | 单词跳转                                  |
| `<leader>f`         | 搜索~目录下的文件                         |
| `<leader>F`         | 搜索当前目录下的文本                      |
| `<leader>g`         | 显示git仓库提交记录                       |
| `<leader>G`         | 显示当前文件提交记录                      |
| `<leader>gg`        | 显示当前文件在某个commit下的完整内容      |
| `<leader>ff`        | 语法错误自动修复(FixIt)                   |
| `<c-p>`             | 切换到上一个buffer                        |
| `<c-n>`             | 切换到下一个buffer                        |
| `<leader>d`         | 删除当前buffer                            |
| `<leader>D`         | 删除当前buffer外的所有buffer              |
| `vim`               | 运行vim编辑器时,默认启动开始页面          |
| `<F5>`              | 显示语法错误提示窗口                      |
| `<F9>`              | 显示上一主题                              |
| `<F10>`             | 显示下一主题                              |
| `<leader>l`         | 按竖线对齐                                |
| `<leader>=`         | 按等号对齐                                |
| `Ya`                | 复制行文本到字母a                         |
| `Da`                | 剪切行文本到字母a                         |
| `Ca`                | 改写行文本到字母a                         |
| `rr`                | 替换文本                                  |
| `<leader>r`         | 全局替换，目前只支持单个文件              |
| `rev`               | 翻转当前光标下的单词或使用V模式选择的文本 |
| `gcc`               | 注释代码                                  |
| `gcap`              | 注释段落                                  |
| `vif`               | 选中函数内容                              |
| `dif`               | 删除函数内容                              |
| `cif`               | 改写函数内容                              |
| `vaf`               | 选中函数内容（包括函数名 花括号）         |
| `daf`               | 删除函数内容（包括函数名 花括号）         |
| `caf`               | 改写函数内容（包括函数名 花括号）         |
| `fa`                | 查找字母a，然后再按f键查找下一个          |
| `<leader>e`         | 快速编辑~/.vimrc文件                      |
| `<leader>s`         | 重新加载~/.vimrc文件                      |
| `<leader>vp`        | 快速编辑~/.vimrc.custom.plugins文件       |
| `<leader>vc`        | 快速编辑~/.vimrc.custom.config文件        |
| `<leader>h`         | 打开vimplus帮助文档                       |
| `<leader>H`         | 打开当前光标所在单词的vim帮助文档         |
| `<leader><leader>t` | 生成try-catch代码块                       |
| `<leader><leader>y` | 复制当前选中到系统剪切板                  |
| `<leader><leader>i` | 安装插件                                  |
| `<leader><leader>u` | 更新插件                                  |
| `<leader><leader>c` | 删除插件                                  |

[3]: https://brew.sh/
[4]: https://github.com/junegunn/vim-plug
[5]: https://github.com/Valloric/YouCompleteMe
[6]: https://github.com/preservim/nerdtree
[8]: https://github.com/vim-airline/vim-airline
[9]: https://github.com/powerline/powerline
[10]: https://github.com/jiangmiao/auto-pairs
[12]: https://github.com/ctrlpvim/ctrlp.vim
[13]: https://github.com/preservim/tagbar
[14]: https://github.com/vim-scripts/taglist.vim
[15]: https://github.com/ryanoasis/vim-devicons
[16]: https://github.com/tpope/vim-surround
[17]: https://github.com/tpope/vim-commentary
[18]: https://github.com/tpope/vim-repeat
[19]: https://github.com/tpope/vim-endwise
[20]: https://github.com/godlygeek/tabular
[23]: https://github.com/easymotion/vim-easymotion
[24]: https://github.com/haya14busa/incsearch.vim
[25]: https://github.com/mhinz/vim-startify
[27]: https://github.com/chxuan/change-colorscheme
[36]: https://github.com/tpope/vim-fugitive
[38]: https://github.com/Valloric/YouCompleteMe
[39]: https://github.com/chxuan/vimplus/issues
[50]: https://github.com/junegunn/vim-slash
[51]: https://github.com/ryanoasis/nerd-fonts
[52]: https://github.com/tiagofumo/vim-nerdtree-syntax-highlight
[53]: https://github.com/Xuyuanp/nerdtree-git-plugin
[54]: https://github.com/VundleVim/Vundle.vim
[56]: https://github.com/Yggdroot/LeaderF
[57]: https://github.com/Shougo/echodoc.vim
[58]: https://github.com/chxuan/cpp-mode
[59]: https://github.com/chxuan/vimplus/blob/master/help.md
[60]: https://github.com/terryma/vim-smooth-scroll
[62]: https://github.com/mileszs/ack.vim
[64]: https://github.com/junegunn/gv.vim
[66]: https://github.com/chxuan/vimplus-startify
[67]: https://github.com/chxuan/prepare-code
[68]: https://github.com/rhysd/clever-f.vim
[70]: https://github.com/chxuan/vim-buffer
[72]: https://github.com/chxuan/vim-edit
[75]: https://github.com/chxuan/vimplus/blob/master/LICENSE
[76]: https://blog.csdn.net/wang73ying/article/details/82491993
[77]: https://blog.csdn.net/liuyangbo121/article/details/82971736
[78]: https://github.com/chxuan/vimplus/blob/master/install.sh
[79]: https://hub.docker.com/r/chxuan/ubuntu-vimplus
[80]: https://github.com/zhoumengkang
[81]: https://github.com/chxuan/vimplus/issues/208
[82]: https://github.com/chxuan/vimplus/blob/master/.vimrc
[83]: https://github.com/chxuan/vimplus/blob/master/.vimrc.custom.plugins
[84]: https://github.com/chxuan/vimplus/blob/master/.vimrc.custom.config
[85]: https://github.com/zibraque
[86]: https://github.com/gfreewind
[87]: https://termux.com/
[88]: https://github.com/wh656325437
[89]: https://github.com/luguifang
[90]: https://github.com/liyewen521
[91]: https://github.com/xht19980305

