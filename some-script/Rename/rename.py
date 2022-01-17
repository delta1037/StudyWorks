import os
import shutil
import getopt
import sys

def createfile(desfile, num):
    abspath = os.path.abspath('.')
    packpath = os.path.join(abspath, desfile + num.__str__())
    if not os.path.exists(packpath):
        os.mkdir(packpath)
    else:
        print('the destination file'+desfile + num.__str__()+'is exits...')
        exit

    return packpath


def main(index, sourcefile, desfile, width):
    if not os.path.isdir(sourcefile):
        return False

    files = os.listdir(sourcefile)
    # file list

    i = 0
    num = 0
    pack = createfile(desfile, i)

    text_ext = ['.txt']

    imagelist = []
    textlist = []

    for filename in files:
        file = os.path.splitext(filename)
        file_ext = file[-1]
        if file_ext in text_ext:
            textlist.append(filename)
        else:
            imagelist.append(filename)

    for filename in imagelist:
        file = os.path.splitext(filename)
        file_f = file[0]
        textname = file_f+'.txt'
        if textname in textlist:
            image = os.path.join(sourcefile, filename)
            text = os.path.join(sourcefile, textname)

            n_image = os.path.join(pack, str(index).zfill(width)+file[1])
            n_text = os.path.join(pack, str(index).zfill(width)+'.txt')

            index=int(index)+1

            shutil.move(image, n_image)
            shutil.move(text, n_text)

            num = num + 1
            if num % 50 == 0:
                i = i + 1
                pack = createfile(desfile, i)


def helper():
    print('-i 命名起始编号')
    print('-s 图片源目录')
    print('-d 图片移动的目的地,自动分包后缀+数字(0,1,2...),默认为picPack')
    print('-w 命名位宽,默认为6(000000)')
    print('-h 查看帮助信息')


index = 1
sourcefile = ''
desfile = 'picPack'
width = 6
opts, args = getopt.getopt(sys.argv[1:], "hi:s:d:w")
for op, value in opts:
    if op == '-i':
        index = int(value)
    elif op == '-s':
        sourcefile = value
    elif op == '-d':
        desfile = value
    elif op == '-w':
        width = value
    elif op == '-h':
        helper()

main(index, sourcefile, desfile, width)
