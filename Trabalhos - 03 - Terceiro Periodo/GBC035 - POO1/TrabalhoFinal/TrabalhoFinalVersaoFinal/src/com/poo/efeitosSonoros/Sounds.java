package com.poo.efeitosSonoros;

import java.applet.*;
import java.io.*;
import java.net.URL;
import javax.sound.sampled.*;

public class Sounds {

    Clip clip;
    AudioClip audio;

    public void playShot(String address) {
        URL url = getClass().getResource(address + ".wav");
        audio = Applet.newAudioClip(url);
        audio.play();
    }

    public void playWavLoop(String address) {
        try {
            URL wav = getClass().getResource(address + ".wav");
            AudioInputStream audioIn = AudioSystem.getAudioInputStream(wav);
            clip = AudioSystem.getClip();
            clip.open(audioIn);
            clip.start();
            clip.loop(Clip.LOOP_CONTINUOUSLY);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public void stopSounds() {
        clip.stop();
    }

}
