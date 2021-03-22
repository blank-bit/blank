void producer()
{
    do
    {
        … produce an item in nextp；
            Wait(mutex) ；(Wait(empty) ；)
                Wait(empty) ；(Wait(mutex) ；)
                    Buffer(in) ： = nextp；(in： = (in + 1) mod n；)
                        Signal(mutex) ；(signal(full) ；)
    } while (TRUE);
}
void consumer()
{
    do
    {
        Wait(mutex) ；(Wait(full) ；)
            Wait(full) ；(Wait(mutex) ；)
                Nextc： = buffer(out) ；
                    Out： = out + 1；(Out： = (out + 1) mod n；)
                                      Signal(mutex) ；(signal(empty) ；)
                                          Consume item in nextc；
    } while (TRUE);
}
