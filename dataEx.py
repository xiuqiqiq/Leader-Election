import re
import collections

import subprocess
import os

def runMurphi(name, murphi_dir, aux_para=''):
    # run murphi
    process1 = subprocess.Popen("{0}/src/mu {1}.m".format(murphi_dir,name),shell=True,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
    (stdout, stderr) = process1.communicate()
    if not re.search(r'Code generated', stdout.decode('utf-8')):
        print(stderr.decode('utf-8'))
        raise ValueError

    # run g++
    command2 = "g++ -ggdb -o {0}.o {0}.cpp -I {1}/include -lm".format(name, murphi_dir)
    process2 = subprocess.Popen(command2, shell=True,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
    process2.communicate()
    if not os.path.exists("./{0}.o".format(name)): raise FileExistsError

    # obtain states and save to txt
    process = subprocess.Popen("./{0}.o {1}".format(name, aux_para), shell=True,
                               stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE)

    (stdoutdata, stderrdata) = process.communicate()

    pattern_counter = re.compile(r'Invariant\s"(\w+).*"\sfailed')
    counter_ex = re.findall(pattern_counter, stdoutdata.decode('utf-8'))
    print('counter_ex:', counter_ex)

    return counter_ex[0] if len(counter_ex) else 0




def txt2csv(data_dir, name, replace_index=None):
    print('txt2csv...')
    prefix_filename = '{0}/{1}'.format(data_dir, name)
    csv_filename = prefix_filename + '.csv'
    txt_filename = prefix_filename + '.txt'
    reachset = open(txt_filename).read()

    # 是否要做变量替换。ex:把node1->i，node2->j
    if replace_index:
        for k, v in replace_index.items():
            print('replace %s by %s' % (k, v))
            reachset = reachset.replace(k, v)
    states = re.findall(r'State\s\d+:\n(.*?)\n\n', reachset, re.S)
    print(states)
    variables = [var.split(':')[0] for var in states[0].split('\n')]

    dataset = [variables]
    open(csv_filename, 'w').write("{}\n".format("".join(variables)))

    stateDict = collections.defaultdict(set)

    for state in states:
        for var in state.split('\n'):
            stateDict[var.split(":")[0]].add(var.split(":")[1])
        dataset.append([var.split(':')[1] for var in state.split('\n')])

    with open(csv_filename, 'w') as f:
        for line in dataset:
            f.write(','.join(line) + '\n')




if __name__ == "__main__":
    name = "v4"
    data_dir = "./murphi_model/"
    murphi_dir = "../../Murphi/cmurphi5.5.0/"
    runMurphi('{0}/{1}'.format(data_dir, name), murphi_dir, '-p >{0}/{1}.txt'.format(data_dir, name))
    # txt2csv(data_dir, name)
