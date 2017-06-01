import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

mnist = input_data.read_data_sets('MNIST_data', one_hot=True)

x=tf.placeholder("float",[None,28*28])
y=tf.placeholder("float",[None,10])

sess = tf.InteractiveSession()

W_h1=tf.Variable(tf.truncated_normal([28*28,32],stddev=0.1))
b_h1=tf.Variable(tf.constant(0.1,"float",[32]))

W_h2=tf.Variable(tf.truncated_normal([32,16],stddev=0.1))
b_h2=tf.Variable(tf.constant(0.1,"float",[16]))

W_h3=tf.Variable(tf.truncated_normal([16,10],stddev=0.1))
b_h3=tf.Variable(tf.constant(0.1,"float",[10]))

h1=tf.nn.relu(tf.matmul(x,W_h1)+b_h1)
h2=tf.nn.relu(tf.matmul(h1,W_h2)+b_h2)
h3=tf.nn.relu(tf.matmul(h2,W_h3)+b_h3)
output=tf.nn.softmax(h3)
cross_entropy=-tf.reduce_sum(y*tf.log(output))

train_step = tf.train.GradientDescentOptimizer(0.01).minimize(cross_entropy)
correct_prediction = tf.equal(tf.argmax(output,1), tf.argmax(y,1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, dtype=tf.float32))

sess.run(tf.global_variables_initializer())

for i in range(10000):
  batch = mnist.train.next_batch(50)
  if i%100 == 0:
    train_accuracy = accuracy.eval(feed_dict={x: mnist.test.images, y: mnist.test.labels})
    print ("step %d, training accuracy %f"%(i, train_accuracy))
  train_step.run(feed_dict={x: batch[0], y: batch[1]})

print ("test accuracy %f"%accuracy.eval(feed_dict={x: mnist.test.images, y: mnist.test.labels}))
sess.close()
